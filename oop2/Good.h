#pragma  once

#include "Facade.h"

class Good : public Facade {
protected:
    int UUID_;
    std::string name_;
    double price_;
    int amount_ = 0;
public:
    Good() = default;

    Good(int UUID, std::string name, double price, int amount) : UUID_(UUID), name_(std::move(name)), price_(price), amount_(amount) {}

    friend std::ostream& operator<<(std::ostream& out, Good &good) {
        return out << good.name_ << " {UUID = " << good.UUID_ << ", price = " << good.price_ << ", amount = " << good.amount_ << "}\n";
    }
};