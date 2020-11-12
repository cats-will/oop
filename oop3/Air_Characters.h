#pragma once

#include "TypeVehicle.h"


class FlyingCarpet : public AirVehicle {
    std::string name = "FlyingCarpet";
    int Speed = 10;
public:
    FlyingCarpet() = default;

    double Time(int S) override {
        if (S <= 1000) {
            return S / Speed;
        }
        if (1000 < S  && S <= 5000) {
            return (S * 0.03) / Speed;
        }
        if (5000 < S && S <= 10000) {
            return (S * 0.1) / Speed;
        }
        if (S > 10000) {
            return (S * 0.05) / Speed;
        }
        return 0;
    }

    std::string GetName() const override {
        return name;
    }
};


class Stypa : public AirVehicle {
    std::string name = "Stypa";
    int Speed = 8;
public:
    double Time(int S) override {
        return (S * 0.06) / Speed;
    }

    std::string GetName() const override {
        return name;
    }
};


class Broom : public AirVehicle {
    std::string name = "Broom";
    int Speed = 20;
public:
    Broom() = default;

    double Time(int S) override {

        int DistanceReducer = 0;
        double prev_dist = 1000;
        double time = 0;

        while(S != 0) {
            if (S < 1000) {
                time += S / Speed;
                break;
            }
            else {
                time += prev_dist * 0.99 / Speed;
                prev_dist = prev_dist * 0.99;
                S -= 1000;
                DistanceReducer++;
            }
        }
        return time;
    }

    std::string GetName() const override {
        return name;
    }
};
