#pragma once

#include "TypeVehicle.h"


class BactrianCamel : public GroundVehicle {
    std::string name = "Bactrian Camel";
    int Speed = 10;
    int RestInterval = 30;
    double RestDuration = 5;
    int number_RestDuration = 0;
public:
    BactrianCamel() = default;

    double Time(int S) override {
        double dist = 0;
        double time = 0;
        while (dist < S) {
            if (dist < S && dist + Speed*RestInterval > S) {
                double rest = S - dist;
                time += rest / Speed;
                dist += rest;
            }
            else {
                if (number_RestDuration >= 1) {
                    RestDuration = 8;
                }
                dist += Speed * RestInterval;
                time += RestInterval + RestDuration;
                number_RestDuration ++;
            }
        }
        return time;
    }

    std::string GetName() const override {
        return name;
    }
};


class SpeedCamel : public GroundVehicle {
    std::string name = "Speed Camel";
    int Speed = 40;
    int RestInterval = 10;
    double RestDuration = 5;
    int number_RestDuration = 0;
public:
    SpeedCamel() = default;

    double Time(int S) override {
        double dist = 0;
        double time = 0;
        while (dist < S) {
            if (dist < S && dist + Speed*RestInterval > S) {
                double rest = S - dist;
                time += rest / Speed;
                dist += rest;
            }
            else {
                if (number_RestDuration == 1) {
                    RestDuration = 6.5;
                }
                if (number_RestDuration >= 2) {
                    RestDuration = 8;
                }
                dist += Speed * RestInterval;
                time += RestInterval + RestDuration;
                number_RestDuration ++;
            }
        }
        return time;
    }

    std::string GetName() const override {
        return name;
    }
};


class Centaur : public GroundVehicle  {
    std::string name = "Centaur";
    int Speed = 15;
    int RestInterval = 8;
    double RestDuration = 2;
public:
    Centaur() = default;

    double Time(int S) override {
        double dist = 0;
        double time = 0;
        while (dist < S) {
            if (dist < S && dist + Speed*RestInterval > S) {
                double rest = S - dist;
                time += rest / Speed;
                dist += rest;
            }
            else {
                dist += Speed * RestInterval;
                time += RestInterval + RestDuration;
            }
        }
        return time;
    }

    std::string GetName() const override {
        return name;
    }
};


class RoverBoots : public GroundVehicle {
    std::string name = "RoverBoots";
    int Speed = 6;
    int RestInterval = 60;
    double RestDuration = 10;
    int number_RestDuration = 0;
public:
    RoverBoots() = default;

    double Time(int S) override {
        double dist = 0;
        double time = 0;
        while (dist < S) {
            if (dist < S && dist + Speed*RestInterval > S) {
                double rest = S - dist;
                time += rest / Speed;
                dist += rest;
            }
            else {
                if (number_RestDuration >= 1) {
                    RestDuration = 5;
                }
                dist += Speed * RestInterval;
                time += RestInterval + RestDuration;
                number_RestDuration ++;
            }
        }
        return time;
    }

    std::string GetName() const override {
        return name;
    }
};















