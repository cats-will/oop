#include "TeamLead.h"

#include <utility>

TeamLead::TeamLead(std::string name_) : name(name_) {}

TeamLead::TeamLead(std::string name_, std::list<IEmployee *> subordinates_) : name(name_) {
    for(auto &it : subordinates_) {
        subordinates.push_back(it);
        if (it->GetLeader() == nullptr) {
            it->SetLeader(this);
        }
    }
}

void TeamLead::SetLeader(IEmployee *leader_) {
    throw TeamLeadException();
}

void TeamLead::AddSubordinate(IEmployee *subordinate) {
    for(auto &item : subordinates) {
        if(item->GetName() == subordinate->GetName()) {
            throw SameEmployeeException();
        }
    }
    subordinates.push_back(subordinate);
}

std::string TeamLead::GetName() const {
    return name;
}

void TeamLead::Print(int level) {
    std::cout << "TemLead - " << GetName();
    for(int i = 0; i < level; ++i) {
        for (auto &it : subordinates) {
            if (it->GetLeader() == this) {
                std::cout << '\n';
                std::cout << "     ";
                it->Print(level + 1);
            } else {
                std::cout << '\n';
                std::cout << "     ";
                it->Print(level + 2);
            }
        }
    }
}

IEmployee *TeamLead::GetLeader() const {
    throw TeamLeadException();
}

void TeamLead::ChangeReportState(Report &report) {
    report.ChangeReportState();
}
