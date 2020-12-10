#pragma once

#include "IAccount.h"

class Deposit : public IAccount {
    bu::uuid uuid = bu::random_generator()();
    bg::date DateEnd;
    float money;
    float percent;
    float bonus;
    unsigned short int HowManyDays = 0;
public:

    Deposit(float money, bg::date date) : money(money), DateEnd(date) {
        if (money < 50000) {
             percent = 3;
        }
        if (money >= 50000 && money <= 100000) {
             percent = 3.5;
        }
        if (money > 100000) {
             percent = 4;
        }
    }

    void WithdrawMoney(float want) override {
        Recalculate();
        if (bg::day_clock::local_day() > DateEnd) {
            throw WithdrawException();
        }
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

        if (bg::day_clock::local_day() > DateEnd) {
            throw WithdrawException();
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
        unsigned int days = bg::day_clock::local_day().day() - DateEnd.day();
        if (days == 0) {
            return;
        }

        for (int i = 0; i < days; i++) {
            bonus += (money + bonus) * percent / 365 / 100;
        }

        DateEnd = bg::day_clock::local_day();
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
        return money;
    }

};