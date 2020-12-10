#ifndef OOP5_IACCOUNT_H
#define OOP5_IACCOUNT_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "boost/date_time/gregorian/gregorian.hpp"

#include "MyException.h"

namespace bu = boost::uuids;
namespace bg = boost::gregorian;

class IAccount {
public:
    virtual void WithdrawMoney(float want) = 0; // снять
    virtual void TopUp(float add) = 0;         // пополнить
    virtual void TransferMoney(IAccount *account, float _money) = 0; // перевести
    virtual void GetTransfer(float _money) = 0;
    virtual bu::uuid GetID() = 0;
    virtual float GetBalance() = 0;
};















#endif //OOP5_IACCOUNT_H
