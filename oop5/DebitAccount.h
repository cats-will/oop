#pragma once

#include "IAccount.h"

class DebitAccount : public IAccount {
    bu::uuid uuid = bu::random_generator()();
    float money;
    float percent;
    bg::date date;
    float bonus = 0;
    unsigned short int HowManyDays = 0;
    float commission;
public:

    DebitAccount(float money, float percent, bg::date date);

    void WithdrawMoney(float want) override;

    void TopUp(float add) override;

    void TransferMoney(IAccount *account, float _money) override;

    void GetTransfer(float _money) override;

    void Recalculate();

    bu::uuid GetID() override;

    float GetBalance() override;

    void SetCommission(float commission_) override;

};