#include "CreditAccount.h"

CreditAccount::CreditAccount(float money, float percent, float limit) : money(money), percent(percent), limit(limit) {}


void CreditAccount::WithdrawMoney(float want) {

    PayCommission();

    if (money - want < -limit && money - want > limit) {
        throw LimitException();
    }

    money -= want;
}


void CreditAccount::TopUp(float add) {
    if (money + add > limit) {
        throw LimitException();
    }
    money += add;
}

void CreditAccount::TransferMoney(IAccount *account, float _money) {

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

void CreditAccount::GetTransfer(float _money) {
    money += _money;
}

void CreditAccount::PayCommission() {
    if (money > 0) {
        return;
    } else if (money < 0 && money - percent > limit && money - percent < -limit) {
        money -= money * percent / 100;
    } else {
        throw LimitException();
    }
}

bu::uuid CreditAccount::GetID() {
    return uuid;
}

float CreditAccount::GetBalance() {
    return money;
}

void CreditAccount::SetCommission(float commission_) {
    commission = commission_;
}