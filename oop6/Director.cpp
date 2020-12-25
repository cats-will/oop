#include "Director.h"

#include <utility>

Director::Director(std::string name_) : name(std::move(name_)) {}

void Director::SetLeader(IEmployee *leader_) {
    leader = leader_;
}

void Director::AddSubordinate(IEmployee *subordinate) {
    subordinates.push_back(subordinate);
    subordinate->SetLeader(this);
}

std::string Director::GetName() const {
    return name;
}

void Director::Print(int level) {
    std::cout << "Director - " << GetName();
    for (auto &it : subordinates) {
        std::cout << '\n';
        for(int j = 0; j < level; j++) {
            std::cout << "     ";
        }
        it->Print(level + 1);
    }
}

IEmployee *Director::GetLeader() const {
    return leader;
}