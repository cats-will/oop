#pragma once

#include "Task.h"

class TaskManagementSystem {
    std::list<Task> tasks;
public:
    TaskManagementSystem() = default;
    explicit TaskManagementSystem(std::list<Task> tasks_);

    void CreateTask(std::string name_, std::string description_, IEmployee *owner_);
    void AddTask(Task task);

    void FindTaskByID(bu::uuid id);
    void FindTaskByOwner(IEmployee *owner);
    void FindByTime(boost::posix_time::ptime last_change);
    void FindEditableTasks();

    void GetTasksAssignedToSubordinates(IEmployee *leader);

    void ChangeTaskState(std::string name, state state_);
    void ChangeTaskOwner(std::string name, IEmployee *owner_);

    void AddCommentToTask(std::string name, std::string comm);

    void ShowState(std::string name);
    void ShowTask(std::string name);
};