#pragma once

#include "IAccount.h"

class CreditAccount : public IAccount {
    bu::uuid uuid = bu::random_generator()();
    float money;
    float commission;
    float limit;
public:

    CreditAccount(float money, float commission, float limit) : money(money), commission(commission), limit(limit) {}

    void WithdrawMoney(float want) override {

        PayCommission();

        if (money - want < -limit && money - want > limit) {
            throw LimitException();
        }

        money -= want;
    }

    void TopUp(float add) override {
        if (money + add > limit) {
            throw LimitException();
        }
        money += add;
    }

    void TransferMoney(IAccount *account, float _money) override {

        PayCommission();

        if (account->GetID() == uuid) {
            throw SelfTransferException();
        }

        if (money - _money < -limit && money - _money > limit) {
            throw LimitException();
        }

        account->GetTransfer(_money);

        money -= _money;
    }

    void GetTransfer(float _money) override {
        money += _money;
    }

    void PayCommission() {
        if (money > 0) {
            return;
        }
        else if (money < 0 && money - commission > limit && money - commission < -limit) {
            money -= money * commission / 100;
        }
        else {
            throw LimitException();
        }
    }

    bu::uuid GetID() override {
        return uuid;
    }

    float GetBalance() override {
        return money;
    }
};