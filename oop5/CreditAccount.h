#pragma once

#include "IAccount.h"

class CreditAccount : public IAccount {
    bu::uuid uuid = bu::random_generator()();
    float money;
    float commission;
    float percent;
    float limit;
public:

    CreditAccount() = default;

    CreditAccount(float money, float percent, float limit);

    void WithdrawMoney(float want) override;

    void TopUp(float add) override;

    void TransferMoney(IAccount *account, float _money) override;

    void GetTransfer(float _money) override;

    void PayCommission();

    bu::uuid GetID() override;

    float GetBalance() override;

    void SetCommission(float commission_) override;
};