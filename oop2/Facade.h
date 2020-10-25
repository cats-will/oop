#pragma once

#include "Good.h"


class Facade {
public:
     Good CreateGood(int UUID, std::string name) {
         return Good(UUID, name);
     }

     Shipment CreateShipment(Good good, double price, int amount) {
         return Shipment(good, price, amount);
     }

     Shop CreateShop(std::string name, Shipment item) {
         return Shop(name, item);
     }

    void ShowGood(Good &gd) const {
        std::cout << gd;
    }

    void ShowShop(Shop &shop) const {
        std::cout << shop;
    }


};