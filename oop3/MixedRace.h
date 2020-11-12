#pragma once

#include "Vehicle.h"
#include "Race.h"

class MixedRace : public Race {
    std::list<Vehicle *> mixed_race;

public:
    explicit MixedRace(std::list<Vehicle *> mixed_race) : mixed_race(mixed_race) {}

    void HowWin(int S) override {
        double min_time = std::numeric_limits<double>::max();
        std::list<std::pair<Vehicle*, double>> winner;
        for (auto &item : mixed_race)
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


    std::list<Vehicle *> GetMixedRace() const
    {
        return mixed_race;
    }
};