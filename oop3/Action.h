#pragma once

#include <utility>
#include <vector>


class Ground {
    int Speed;
    int RestInterval;
    double RestDuration_first;
    double RestDuration_second;
    double RestDuration_last;
    double RestDuration_const;
public:
    Ground() = default;

    Ground(int Speed, int RestInterval, double RestDuration_first, double RestDuration_last) : Speed(Speed), RestInterval(RestInterval), RestDuration_first(RestDuration_first), RestDuration_last(RestDuration_last) {}

    Ground(int Speed, int RestInterval, double RestDuration_first, double RestDuration_second, double RestDuration_last) : Speed(Speed), RestInterval(RestInterval), RestDuration_first(RestDuration_first), RestDuration_second(RestDuration_second), RestDuration_last(RestDuration_last) {}

    Ground(int Speed, int RestInterval, double RestDuration_const) : Speed(Speed), RestInterval(RestInterval), RestDuration_const(RestDuration_const) {}

    std::pair<Ground, Ground> CreateRace(Ground man1, Ground man2) {
        std::pair<Ground, Ground> Race;
        Race.first = man1;
        Race.second = man2;
        return Race;
    }

    int GetSpeed() const {
        return Speed;
    }

    int GetRestInterval() const {
        return RestInterval;
    }

    double GetRestDuration_first() const {
        return RestDuration_first;
    }

    double GetRestDuration_second() const {
        return RestDuration_second;
    }

    double GetRestDuration_last() const {
        return RestDuration_last;
    }

    double GetRestDuration_const() const {
        return RestDuration_const;
    }
};

class Air {
    int Speed;
    std::vector<std::pair<int, int>> DistanceReducer; // in %
public:
    Air() = default;
};