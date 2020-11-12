#pragma once

#include <limits>
#include "Ground_Charaster.h"
#include "Race.h"

class GroundRace : public Race {
    std::list<GroundVehicle *> ground_race;
public:
    explicit GroundRace(std::list<GroundVehicle *> ground_race) : ground_race(ground_race) {}

    void HowWin(int S) override {
        double min_time = std::numeric_limits<double>::max();
        std::list<std::pair<GroundVehicle*, double>> winner;
        for (auto &item : ground_race)
        {
            double time = item->Time(S);
            if (time < min_time)
            {
                min_time = time;
                winner.push_front(std::make_pair(item, time));
            }
        }
        std::cout << "Winner is: " << winner.front().first->GetName() << ", time:" << winner.front().second << '\n';
    }
};