#pragma once

#include "TaskManagementSystem.h"

class Report {
    std::list<TaskManagementSystem> SavedDayReport;
    std::list<TaskManagementSystem> EditedDayReport;
public:
    Report() = default;
    void AddToDayReport(TaskManagementSystem &task);
    void EditDayReport(TaskManagementSystem &task);
    void SaveDayReport(TaskManagementSystem &task);
};