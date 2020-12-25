#pragma once

#include "IEmployee.h"

class Director : public IEmployee {
    std::string name;
    IEmployee* leader;
    std::list<IEmployee*> subordinates;
public:
    explicit Director(std::string name_);
    void SetLeader(IEmployee* leader_) override;
    void AddSubordinate(IEmployee* subordinate) override;
    std::string GetName() const override;
    IEmployee* GetLeader() const override;
    void Print(int level = 0) override;
};