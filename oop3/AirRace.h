#pragma once

#include "Air_Characters.h"
#include "Race.h"

class AirRace : public Race {
    std::list<AirVehicle *> air_race;
public:
    explicit AirRace(std::list<AirVehicle *> air_race) : air_race(air_race) {}

    void HowWin(int S) override {
        double min_time = std::numeric_limits<double>::max();
        std::list<std::pair<AirVehicle*, double>> winner;
        for (auto &item : air_race)
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