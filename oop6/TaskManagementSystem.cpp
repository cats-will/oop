#include "TaskManagementSystem.h"

TaskManagementSystem::TaskManagementSystem(std::list<Task> tasks_) {
    for(auto &item : tasks_) {
        tasks.push_back(item);
    }
}

Task TaskManagementSystem::FindTaskByID(bu::uuid id) {
    for(auto &item : tasks) {
        if (item.GetID() == id) {
            return item;
        }
    }
}

void TaskManagementSystem::AddTask(Task task) {
    tasks.push_back(task);
}

Task TaskManagementSystem::CreateTask(std::string name_, std::string description_, IEmployee *owner_) {
    AddTask(Task(name_, description_, owner_));
    return Task(name_, description_, owner_);
}
