#pragma once

#include "IAccount.h"

class Deposit : public IAccount {
    bu::uuid uuid = bu::random_generator()();
    bg::date DateEnd;
    float money;
    float percent;
    float bonus;
    unsigned short int HowManyDays = 0;
    float commission;
public:

    Deposit(float money, bg::date date);

    void WithdrawMoney(float want) override;

    void TopUp(float add) override;

    void TransferMoney(IAccount *account, float _money) override;

    void GetTransfer(float _money) override;

    void Recalculate();

    bu::uuid GetID() override;

    float GetBalance() override;

    void SetCommission(float commission_) override;
};