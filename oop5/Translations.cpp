#include "Translations.h"

Translations::Translations(IAccount *who, IAccount *whom, float _money) : who(who), whom(whom), _money(_money) {}


IAccount* Translations::GetWho() const {
    return who;
}


IAccount* Translations::GetWhom() const {
    return whom;
}


float Translations::GetMoney() const {
    return _money;
}