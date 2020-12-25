#pragma once

#include "TaskManagementSystem.h"

class Report {
    bg::date today = bg::day_clock::local_day();

    std::list<TaskManagementSystem> EditedDayReport;
    std::list<TaskManagementSystem> SavedDayReport;
public:
    Report() = default;
    void AddToDayReport(TaskManagementSystem &task);
    void EditDayReport_State(TaskManagementSystem &task, state new_state);
    void EditDayReport_Comment(TaskManagementSystem &task, IEmployee* new_owner);
    void EditDayReport_Owner(TaskManagementSystem &task, std::string new_comment);
    void SaveDayReport(TaskManagementSystem &task);
    void ShowCompleteTasks();
};