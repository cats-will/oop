#pragma once

#include "Good.h"

class Shipment {
private:
    Good good_;
    double price_;
    int amount_ = 0;
public:
    Shipment(Good good, double price, int amount) : good_(std::move(good)), price_(price), amount_(amount) {}

    Good Get_Good() const {
        return good_;
    }

    double Get_Price() const {
        return price_;
    }

    void ChangeAmount(int n) {
        amount_ -= n;
    }

    int& Get_Amount() {
        return amount_;
    }

    void Set_Price(double price) {
        price_ = price;
    }
};