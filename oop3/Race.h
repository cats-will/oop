#pragma once

#include "Vehicle.h"
#include "Ground_Charaster.h"
#include "Air_Characters.h"

class Race {
    std::list<GroundVehicle> ground_race;
    std::list<AirVehicle> air_race;
    std::list<Vehicle> mixed_race;
public:
    explicit Race(std::list<GroundVehicle> ground_race) : ground_race(ground_race) {}
    explicit Race(std::list<AirVehicle> air_race) : air_race(air_race) {}
    explicit Race(std::list<Vehicle> mixed_race) : mixed_race(mixed_race) {}

    std::list<GroundVehicle> GetGroundRace() const {
        return ground_race;
    }
    std::list<AirVehicle> GetAirRace() const {
        return air_race;
    }
    std::list<Vehicle> GetMixedRace() const {
        return mixed_race;
    }
};