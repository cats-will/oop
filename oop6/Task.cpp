#include "Task.h"

Task::Task(std::string name_, std::string description_, IEmployee *owner_) : name(name_), description(description_), owner(owner_) {}

void Task::ChangeState(state now) {
    LastCommit = boost::posix_time::second_clock::local_time();
    state_now = now;
}

void Task::AddComment(std::string comm) {
    LastCommit = boost::posix_time::second_clock::local_time();
    comment = comm;
}

void Task::ChangeOwner(IEmployee *new_owner) {
    LastCommit = boost::posix_time::second_clock::local_time();
    owner = new_owner;
}

bu::uuid Task::GetID() const {
    return uuid;
}

boost::posix_time::ptime Task::GetTime() const {
    return CreationTime;
}

