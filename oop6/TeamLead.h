#pragma once

#include "IEmployee.h"


class TeamLead : public IEmployee {
    std::string name;
    std::list<IEmployee*> subordinates;
public:
    explicit TeamLead(std::string name_, std::list<IEmployee*> subordinates_);
    void SetLeader(IEmployee* leader_) override;
    void AddSubordinate(IEmployee* subordinate) override;
    std::string GetName() const override;
    void Print(int level = 0) override;

};