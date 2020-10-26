#pragma once

#include "Good.h"


class Facade {
public:
     Good CreateGood(int UUID, std::string name) {
         return Good(UUID, name);
     }

     std::list<Shipment> CreateShipment_as_list(Good good, double price, int amount) {
         Shipment shipment = Shipment(good, price, amount);
         std::list<Shipment> sh;
         sh.push_back(shipment);
         return sh;
     }

     Shipment CreateShipment(Good good, double price, int amount) {
         return Shipment(good, price, amount);
     }

     Shop CreateShop(int id, std::string name, std::list<Shipment> item) {
         return Shop(id, name, item);
     }

    void ShowGood(Good &gd) const {
        std::cout << gd;
    }

    void ShowShop(Shop &shop) const {
        std::cout << shop;
    }

    void add_shipments_from_file(Shop &shop) {

        std::ifstream fin("parties.txt");

        Facade facade;
        int ID;
        std::string name;
        double price;
        int amount;

        while(!fin.eof()) {
            fin >> ID >> name >> price >> amount;
            Shipment shipment = facade.CreateShipment(facade.CreateGood(ID, name), price, amount);
            shop.add_to_shop(shipment);
        }
    }

    Shop Store_creation() {
        std::cout << "Store creation\n";
        std::cout << "Enter store's name: ";
        std:: string shop_name;
        std::cin >> shop_name;
        std::cout << '\n';
        std::cout << "and it's ID: ";
        int id;
        std::cin >> id;
        std::cout << '\n';

        std::cout << "Now add a party of clothes to the store.\n";
        std::cout << "Enter the item uuid: ";
        int uuid;
        std::cin >> uuid;
        std::cout << '\n';

        std::cout << "Enter the item name: ";
        std::string item_name;
        std::cin >> item_name;
        std::cout << '\n';

        std::cout << "Enter the item price: ";
        double cost;
        std::cin >> cost;
        std::cout << '\n';

        std::cout << "Enter amount of item: ";
        int count;
        std::cin >> count;
        std::cout << '\n';

        Shop a = CreateShop(id, shop_name, CreateShipment_as_list(CreateGood(uuid, item_name), cost, count));

        return a;
    }

    void Add_Shipment(Shop &shop) {
        std::cout << "Enter item's UUID: ";
        int uuid;
        std::cin >> uuid;
        std::cout << '\n';

        std::cout << "Enter item's name: ";
        std::string item_name;
        std::cin >> item_name;
        std::cout << '\n';

        std::cout << "Enter item's price: ";
        double price;
        std::cin >> price;
        std::cout << '\n';

        std::cout << "Enter item's amount: ";
        int amount;
        std::cin >> amount;

        Shipment shipment = CreateShipment(CreateGood(uuid, item_name), price, amount);

        shop.add_to_shop(shipment);
    }



};

Shop create() {
    Facade a;
    return a.Store_creation();
}

void add(Shop &shop) {
    Facade a;
    a.Add_Shipment(shop);
}

