#include "DebitAccount.h"

DebitAccount::DebitAccount(float money, float percent, bg::date date) : money(money), percent(percent), date(date) {}


void DebitAccount::WithdrawMoney(float want) {
    Recalculate();
    if (money - want < 0) {
        throw NotEnoughMoneyException();
    }
    if (want < 0) {
        throw InvalidSumException();
    }
    money -= want;
}


void DebitAccount::TopUp(float add) {
    Recalculate();
    if (add <= 0) {
        throw InvalidSumException();
    }
    money += add;
}


void DebitAccount::TransferMoney(IAccount *account, float _money) {
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


void DebitAccount::GetTransfer(float _money) {
    money += _money;
}


void DebitAccount::Recalculate() {
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


bu::uuid DebitAccount::GetID() {
    Recalculate();
    return uuid;
}


float DebitAccount::GetBalance() {
    Recalculate();
    return money;
}


void DebitAccount::SetCommission(float commission_) {
    commission = commission_;
}