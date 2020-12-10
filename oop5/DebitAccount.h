#pragma once

#include "IAccount.h"

class DebitAccount : public IAccount {
    bu::uuid uuid = bu::random_generator()();
    float money;
    float percent;
    bg::date date;
    float bonus = 0;
    unsigned short int HowManyDays = 0;
public:

    DebitAccount(float money, float percent, bg::date date) : money(money), percent(percent), date(date) {}

    void WithdrawMoney(float want) override {
        Recalculate();
        if (money - want < 0) {
            throw NotEnoughMoneyException();
        }
        if (want < 0) {
            throw InvalidSumException();
        }
        money -= want;
    }

    void TopUp(float add) override {
        Recalculate();
        if (add <= 0) {
            throw InvalidSumException();
        }
        money += add;
    }

    void TransferMoney(IAccount *account, float _money) override {
        Recalculate();

        if (account->GetID() == uuid) {
            throw SelfTransferException();
        }

        if (money - _money < 0) {
            throw NotEnoughMoneyException();
        }

        account->GetTransfer(_money);

        money -= _money;
    }

    void GetTransfer(float _money) override {
        money += _money;
    }

    void Recalculate() {
        unsigned int days = bg::day_clock::local_day().day() - date.day();
        if (days == 0) {
            return;
        }

        for (int i = 0; i < days; i++) {
            bonus += (money + bonus) * percent / 365 / 100;
        }

        date = bg::day_clock::local_day();
        HowManyDays += days;

        if (HowManyDays >= 30) {
            money += bonus;
            bonus = 0;
            HowManyDays -= 30;
        }
    }

    bu::uuid GetID() override {
        Recalculate();
        return uuid;
    }

    float GetBalance() override {
        Recalculate();
        return money;
    }


};