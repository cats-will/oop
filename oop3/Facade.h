#pragma once

#include <iostream>
#include "Race.h"
#include "Exception.h"

class Facade {

public:
    void CreateRace() {
        std::cout << "Race's type: 1-ground, 2-air, 3-mixed\n";
        int type;
        std::cin >> type;
        if (type == 1) {
            Race GroundRace(std::list<GroundVehicle> race);
        }
        else if (type == 2) {
            Race AirRace(std:: list<AirVehicle> race);
        }
        else if (type == 3) {
            Race MixedRace(std:: list<Vehicle> race);
        }
        else {
            std::cout << "Wrong type\n";
            exit(-1);
        }

        std::cout << "How many participants?\n";
        int n;
        std::cin >> n;

        for(int i = 0; i < n; i++) {

        }


    }

    GroundVehicle Race(std::list<GroundVehicle> ground, int S) {
        double min_time = std::numeric_limits<double>::max();
        std::list<std::pair<GroundVehicle, double>> winner;
        for(auto &item : ground) {
            double time = item.Time(S);
            if (time < min_time) {
                min_time = time;
                winner.push_front(std::make_pair(item, time));
            }
        }
    }

    void Race(std::list<AirVehicle> air) {}
    void Race(std::list<Vehicle> mixed) {}
};