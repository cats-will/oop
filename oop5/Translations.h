#pragma once

#include "IAccount.h"


class Translations {
    IAccount *who;
    IAccount *whom;
    float _money;
public:
    Translations(IAccount *who, IAccount *whom, float _money);

    IAccount* GetWho() const;

    IAccount* GetWhom() const;

    float GetMoney() const;
};