#pragma once

#include <string>
#include <list>
#include <iostream>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
namespace bu = boost::uuids;
namespace bg = boost::gregorian;

#include "MyException.h"

class IEmployee {
public:
    virtual void SetLeader(IEmployee* leader_) = 0;
    virtual void AddSubordinate(IEmployee* subordinate) = 0;
    virtual std::string GetName() const = 0;
    virtual void Print(int level = 0) = 0;
};