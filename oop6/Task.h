#pragma once

#include "IEmployee.h"

enum state {
    opened,
    active,
    resolved
};

class Task {
    bu::uuid uuid = bu::random_generator()();
    boost::posix_time::ptime CreationTime = boost::posix_time::second_clock::local_time();
    boost::posix_time::ptime LastCommit = boost::posix_time::second_clock::local_time();
    std::string name;
    std::string description;
    std::string comment;
    IEmployee* owner;
    state state_now = opened;
public:
    Task(std::string name_, std::string description_, IEmployee *owner_);
    void ChangeState(state now);
    void AddComment(std::string comm);
    void ChangeOwner(IEmployee* new_owner);
    bu::uuid GetID() const;
    boost::posix_time::ptime GetTime() const;

};