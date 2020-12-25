#pragma once

#include "TaskManagementSystem.h"

class Report {
    bg::date today = bg::day_clock::local_day();
    std::list<TaskManagementSystem> EditedDayReport;
    std::list<TaskManagementSystem> SavedDayReport;

    bg::date_period sprint_period;
    state state_now = active;
    std::list<TaskManagementSystem> EditedSprintReport;
    std::list<TaskManagementSystem> SavedSprintReport;
public:
    Report() = default;

    void AddToDayReport(TaskManagementSystem &task);
    void EditDayReport_State(TaskManagementSystem &task, state new_state);
    void EditDayReport_Owner(TaskManagementSystem &task, IEmployee* new_owner);
    void EditDayReport_Comment(TaskManagementSystem &task, std::string new_comment);
    void SaveDayReport(TaskManagementSystem &task);
    void ShowDayCompleteTasks();

    Report(bg::date start,bg::date end);
    void AddToSprintReport(TaskManagementSystem &task);
    void EditSprintReport_State(TaskManagementSystem &task, state new_state);
    void EditSprintReport_Owner(TaskManagementSystem &task, IEmployee* new_owner);
    void EditSprintReport_Comment(TaskManagementSystem &task, std::string new_comment);
    void SaveSprintReport(TaskManagementSystem &task);
    void ShowSprintCompleteTasks();
    bg::date_period GetSprintPeriod() const;

    void ChangeReportState();
};