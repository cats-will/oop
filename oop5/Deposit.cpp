#include "Deposit.h"

Deposit::Deposit(float money, bg::date date) : money(money), DateEnd(date) {
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


void Deposit::WithdrawMoney(float want) {
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


void Deposit::TopUp(float add) {
    Recalculate();
    if (add <= 0) {
        throw InvalidSumException();
    }

    money += add;
}


void Deposit::TransferMoney(IAccount *account, float _money) {
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


void Deposit::GetTransfer(float _money) {
    money += _money;
}


void Deposit::Recalculate() {
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


bu::uuid Deposit::GetID() {
    Recalculate();
    return uuid;
}


float Deposit::GetBalance() {
    return money;
}


void Deposit::SetCommission(float commission_) {
    commission = commission_;
}