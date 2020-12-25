#include "Report.h"
#include "TeamLead.h"

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

void Report::EditDayReport_Comment(TaskManagementSystem &task, std::string new_comment) {
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

void Report::EditDayReport_Owner(TaskManagementSystem &task, IEmployee *new_owner) {
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

void Report::SaveDayReport(TaskManagementSystem &task) {
    bg::date now = bg::day_clock::local_day();
    if (now == today) {
        SavedDayReport.push_back(task);
    } else {
        throw WrongDayException();
    }
}

void Report::ShowDayCompleteTasks() {
    if (SavedDayReport.empty()) {
        std::cout << "No complete tasks";
    }
    for (auto &item : SavedDayReport) {
        for (auto &it : item.GetTasks()) {
            if (it.GetState() == resolved) {
                item.ShowTask(it.GetName());
            }
        }
    }
}

Report::Report(bg::date start,bg::date end) : sprint_period(start,end) {}

void Report::AddToSprintReport(TaskManagementSystem &task) {
    bg::date now = bg::day_clock::local_day();
    if (!sprint_period.contains(now)) {
        throw SprintPeriodException();
    }
    EditedSprintReport.push_back(task);
}

void Report::EditSprintReport_State(TaskManagementSystem &task, state new_state) {
    int j = 0;
    for (auto &it : EditedSprintReport) {
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

void Report::EditSprintReport_Owner(TaskManagementSystem &task, IEmployee *new_owner) {
    int j = 0;
    for (auto &it : EditedSprintReport) {
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

void Report::EditSprintReport_Comment(TaskManagementSystem &task, std::string new_comment) {
    int j = 0;
    for (auto &it : EditedSprintReport) {
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

void Report::SaveSprintReport(TaskManagementSystem &task) {
    int j = 0;
    for(auto item = EditedSprintReport.begin(); item != EditedSprintReport.end(); item++) {
        for (auto &it : item->GetTasks()) {
            for (auto &i : task.GetTasks()) {
                if (it.GetName() == i.GetName()) {
                    EditedSprintReport.erase(item);
                    ++j;
                    break;
                }
            }
        }
    }

    if (j == 0) {
        throw TaskExistenceException();
    } else {
        SavedDayReport.push_back(task);
    }
}

bg::date_period Report::GetSprintPeriod() const {
    return sprint_period;
}

void Report::ShowSprintCompleteTasks() {
    if (SavedSprintReport.empty()) {
        std::cout << "No complete tasks";
    }
    for (auto &item : SavedSprintReport) {
        for (auto &it : item.GetTasks()) {
            if (it.GetState() == resolved) {
                item.ShowTask(it.GetName());
            }
        }
    }
}

void Report::ChangeReportState() {
    state_now = resolved;
}
