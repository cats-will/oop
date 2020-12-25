#pragma once

#include "IEmployee.h"

class Employee : public IEmployee {
    std::string name;
    IEmployee* leader;
public:
    explicit Employee(std::string name_);
    void SetLeader(IEmployee* leader_) override;
    void AddSubordinate(IEmployee* subordinate) override;
    std::string GetName() const override;
    void Print(int level = 0) override;
    IEmployee* GetLeader() const override;
    void ChangeReportState(Report &report) override;
};