#include "Report.h"

void Report::AddToDayReport(TaskManagementSystem &task) {
    bg::date now = bg::day_clock::local_day();
    if (now == today) {
        EditedDayReport.push_back(task);
    } else {
        throw WrongDayException();
    }
}

void Report::EditDayReport_State(TaskManagementSystem &task, state new_state) {
    int j = 0;
    for (auto &it : EditedDayReport) {
        for (auto &item : it.GetTasks()) {
            for (auto &i : task.GetTasks()) {
                if (item.GetName() == i.GetName()) {
                    item.ChangeState(new_state);
                    ++j;
                }
            }
        }
    } if (j == 0) {
        throw TaskExistenceException();
    }
}

void Report::EditDayReport_Comment(TaskManagementSystem &task, IEmployee *new_owner) {
    int j = 0;
    for (auto &it : EditedDayReport) {
        for (auto &item : it.GetTasks()) {
            for (auto &i : task.GetTasks()) {
                if (item.GetName() == i.GetName()) {
                    item.ChangeOwner(new_owner);
                    ++j;
                }
            }
        }
    } if (j == 0) {
        throw TaskExistenceException();
    }
}

void Report::EditDayReport_Owner(TaskManagementSystem &task, std::string new_comment) {
    int j = 0;
    for (auto &it : EditedDayReport) {
        for (auto &item : it.GetTasks()) {
            for (auto &i : task.GetTasks()) {
                if (item.GetName() == i.GetName()) {
                    item.AddComment(new_comment);
                    ++j;
                }
            }
        }
    } if (j == 0) {
        throw TaskExistenceException();
    }
}

void Report::SaveDayReport(TaskManagementSystem &task) {
    bg::date now = bg::day_clock::local_day();
    if (now == today) {
        SavedDayReport.push_back(task);
    } else {
        throw WrongDayException();
    }
}
//check it
void Report::ShowCompleteTasks() {
    for (auto &item : SavedDayReport) {
        for (auto &it : item.GetTasks()) {
            if (it.GetState() == resolved) {

            }
        }
    }
}
