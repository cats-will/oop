#include "Employee.h"

#include <utility>

Employee::Employee(std::string name_) : name(std::move(name_)) {}

void Employee::SetLeader(IEmployee *leader_) {
    leader = leader_;
}

void Employee::AddSubordinate(IEmployee *subordinate) {
    throw EmployeeException();
}

std::string Employee::GetName() const {
    return name;
}

void Employee::Print(int level) {
    std::cout << "Employee - " << GetName();
}

IEmployee *Employee::GetLeader() const {
    return leader;
}

void Employee::ChangeReportState(Report &report) {
    throw EmployeeReportException();
}
