#pragma once

#include "Task.h"

class TaskManagementSystem {
    std::list<Task> tasks;
public:
    TaskManagementSystem() = default;
    explicit TaskManagementSystem(std::list<Task> tasks_);
    Task CreateTask(std::string name_, std::string description_, IEmployee *owner_);
    void AddTask(Task task);
    Task FindTaskByID(bu::uuid id);
};