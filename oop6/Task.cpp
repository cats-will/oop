#include "Task.h"

Task::Task(std::string name_, std::string description_, IEmployee *owner_) : name(name_), description(description_), owner(owner_) {
    Task task(uuid, Time, name, description, comment, owner, state_now);
    changes.push_back(task);
}

Task::Task(bu::uuid uuid_, boost::posix_time::ptime Time_, std::string name_, std::string description_, std::string comment_, IEmployee *owner_, state state_now_) {
    uuid = uuid_;
    Time = Time_;
    name = name_;
    description = description_;
    comment = comment_;
    owner = owner_;
    state_now = state_now_;
}

void Task::ChangeState(state now) {
    Time = boost::posix_time::second_clock::local_time();
    state_now = now;
    Task task(uuid, Time, name, description, comment, owner, state_now);
    changes.push_back(task);
}

void Task::AddComment(std::string comm) {
    Time = boost::posix_time::second_clock::local_time();
    comment = comm;
    Task task(uuid, Time, name, description, comment, owner, state_now);
    changes.push_back(task);

}

void Task::ChangeOwner(IEmployee *new_owner) {
    Time = boost::posix_time::second_clock::local_time();
    owner = new_owner;
    Task task(uuid, Time, name, description, comment, owner, state_now);
    changes.push_back(task);
}

bu::uuid Task::GetID() const {
    return uuid;
}

boost::posix_time::ptime Task::GetTime() const {
    return Time;
}

IEmployee *Task::GetOwner() const {
    return owner;
}

std::list<Task> Task::GetChanges() const {
    return changes;
}

state Task::GetState() const {
    return state_now;
}

std::string Task::GetName() const {
    return name;
}

std::string Task::GetDescription() const {
    return description;
}

std::string Task::GetComment() const {
    return comment;
}





