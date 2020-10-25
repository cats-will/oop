#pragma  once

#include <string>
#include <iostream>
#include <list>
#include <fstream>

class Good {
private:
    int UUID_;
    std::string name_;
public:
    Good() = default;

    Good(int UUID, std::string name) : UUID_(UUID), name_(name) {}

    int Get_UUID() const {
        return UUID_;
    }

    std::string Get_Name() const {
        return name_;
    }

    friend std::ostream& operator<<(std::ostream& out, Good &good) {
        return out << "UUID:" << good.UUID_ << ", " << "name:" << good.name_ << '\n';
    }
};