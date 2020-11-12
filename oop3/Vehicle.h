#pragma once

#include <utility>
#include <list>
#include <iostream>

class Vehicle {
public:
    virtual double Time(int S) = 0;
    virtual std::string GetName() const = 0;
};
