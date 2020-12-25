#pragma once

#include "IEmployee.h"

enum state {
    opened,
    active,
    resolved
};

class Task {
    bu::uuid uuid = bu::random_generator()();
    boost::posix_time::ptime Time = boost::posix_time::second_clock::local_time();
    std::string name;
    std::string description;
    std::string comment;
    IEmployee* owner;
    state state_now = opened;

    std::list<Task> changes;

    Task(bu::uuid uuid_, boost::posix_time::ptime Time_, std::string name_, std::string description_, std::string comment_, IEmployee *owner_, state state_now_);
public:
    Task(std::string name_, std::string description_, IEmployee *owner_);

    void ChangeState(state now);
    void AddComment(std::string comm);
    void ChangeOwner(IEmployee* new_owner);

    bu::uuid GetID() const;
    std::string GetName() const;
    state GetState() const;
    std::string GetDescription() const;
    std::string GetComment() const;
    boost::posix_time::ptime GetTime() const;
    IEmployee* GetOwner() const;
    std::list<Task> GetChanges() const;
};