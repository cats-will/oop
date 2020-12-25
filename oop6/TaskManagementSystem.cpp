#include "TaskManagementSystem.h"
#include "Employee.h"

TaskManagementSystem::TaskManagementSystem(std::list<Task> tasks_) {
    for(auto &item : tasks_) {
        tasks.push_back(item);
    }
}

void TaskManagementSystem::FindTaskByID(bu::uuid id) {
    int i = 0;
    for (auto &item : tasks) {
        if (item.GetID() == id) {
            ShowTask(item.GetName());
            ++i;
        }
    }
    if (i == 0) {
        throw TaskExistenceException();
    }
}

void TaskManagementSystem::AddTask(Task task) {
    for (auto &it : tasks) {
        if (it.GetName() == task.GetName()) {
            throw TaskNameException();
        }
    }
    tasks.push_back(task);
}

void TaskManagementSystem::CreateTask(std::string name_, std::string description_, IEmployee *owner_) {
    for (auto &it : tasks) {
        if (it.GetName() == name_) {
            throw TaskNameException();
        }
    }
    Task t(name_, description_, owner_);
    AddTask(t);
    std::cout << "UUID of your new task is " << t.GetID() << ", remember it in order to perform any further actions with the task.\n";
}

void TaskManagementSystem::FindTaskByOwner(IEmployee *owner) {
    int i = 0;
    for (auto &item : tasks) {
        if (item.GetOwner()->GetName() == owner->GetName()) {
            ShowTask(item.GetName());
            ++i;
        }
    }
    if (i == 0) {
        throw TaskExistenceException();
    }
}

void TaskManagementSystem::FindByTime(boost::posix_time::ptime last_change) {
    //думать?
    for (auto &item : tasks) {
        if (!(item.GetTime() == last_change)) {
            throw TaskExistenceException();
        } else {
            ShowTask(item.GetName());
        }
    }
}

void TaskManagementSystem::ChangeTaskState(std::string name, state state_) {
    for (auto &it : tasks) {
        if (!(it.GetName() == name)) {
            throw TaskExistenceException();
        }
    }
    for (auto &item : tasks) {
        if (item.GetName() == name) {
            item.ChangeState(state_);
        }
    }
}

void TaskManagementSystem::AddCommentToTask(std::string name, std::string comm) {
    for (auto &it : tasks) {
        if (!(it.GetName() == name)) {
            throw TaskExistenceException();
        }
    }
    for (auto &item : tasks) {
        if (item.GetName() == name) {
            item.AddComment(comm);
        }
    }
}

void TaskManagementSystem::ChangeTaskOwner(std::string name, IEmployee *owner_) {
    for (auto &it : tasks) {
        if (!(it.GetName() == name)) {
            throw TaskExistenceException();
        }
    }
    for (auto &item : tasks) {
        if (item.GetName() == name) {
            item.ChangeOwner(owner_);
        }
    }
}

void TaskManagementSystem::ShowState(std::string name) {
    for (auto &it : tasks) {
        if (!(it.GetName() == name)) {
            throw TaskExistenceException();
        }
    }
    for (auto &it : tasks) {
        if (it.GetName() == name) {
            std::cout << it.GetState();
        }
    }
}

void TaskManagementSystem::ShowTask(std::string name) {
    int i = 0;

    for (auto &item : tasks) {
        if (item.GetName() == name) {
            ++i;

            std::cout << "UUID: " << item.GetID() << '\n';
            std::cout << "Name: " << item.GetName() << '\n';
            std::cout << "Description: " << item.GetDescription() << '\n';

            if (!item.GetComment().empty()) {
                std::cout << "Comment: " << item.GetComment() << '\n';
            }

            std::cout << "Creation time: " << item.GetChanges().front().GetTime() << '\n';

            if (item.GetState() == opened) {
                std::cout << "State: opened\n";
            } else if (item.GetState() == active) {
                std::cout << "State: active\n";
            } else if (item.GetState() == resolved) {
                std::cout << "Status: resolved\n";
            }

            std::cout << "Owner: " << item.GetOwner()->GetName() << '\n';
        }
    }
    if (i == 0) {
        throw TaskExistenceException();
    }
}

void TaskManagementSystem::FindEditableTasks() {
    int i = 0;
    for (auto &it : tasks) {
        if (it.GetChanges().size() > 1) {
            ShowTask(it.GetName());
            std::cout << "\n\n\n";
            ++i;
        }
    }

    if (i == 0) {
        throw TaskExistenceException();
    }
}

void TaskManagementSystem::GetTasksAssignedToSubordinates(IEmployee *leader) {
    if(dynamic_cast<Employee*>(leader)) {
        throw EmployeeException();
    }

    int i = 0;
    for (auto &item : tasks) {
        if (item.GetOwner()->GetLeader() == leader) {
            ShowTask(item.GetName());
            std::cout << "\n\n";
            ++i;
        }
    }
    if (i == 0) {
        throw TaskExistenceException();
    }
}
