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

    void find_the_cheapest(std::list<Shop> &shops, Good &gd) {
        Shop cheap_shop = Shop();
        double cheap_price = std::numeric_limits<double>::max();
        for (auto & it : shops) {
            for (auto & item : it.GetShipment()) {
                if (gd.Get_UUID() == item.Get_Good().Get_UUID() && item.Get_Price() < cheap_price) {
                    cheap_price = item.Get_Price();
                    cheap_shop = it;
                }
            }
        }
        std::cout << cheap_shop.GetName() << ", Price:" << cheap_price;
    }

    void what_is_enough_for(Shop &shop, int &money) {
        std::vector<std::pair<Good, int>> goods;
        for (auto & it : shop.GetShipment()) {
            if (it.Get_Price() <= money) {
                goods.emplace_back(it.Get_Good(), money / it.Get_Price());
            }
        }
        if (goods.empty()) {
            std::cout << "You're nish'enka";
        }
        else {
            for(auto & it : goods) {
                std::cout << it.first.Get_Name() << " - " << it.second << '\n';
            }
        }
    }

    void buy_a_party(Shop &shop, std::list<Good> &parties, int amount) {
        double full_price = 0;
        for (auto & it : shop.GetShipment()) {
            for (auto & item : parties) {
                if (it.Get_Good().Get_UUID() == item.Get_UUID() && it.Get_Amount() >= amount) {
                    full_price += it.Get_Price() * amount;
                }
            }
        }
        if (full_price == 0) {
            std::cout << "There's not enough good in the shop";
        }
        else {
            std::cout << "Total price is " << full_price;
        }
    }

    static void buy_the_cheapest_party(std::list<Shop> &shops, std::list<Shipment> &parties) {
        Shop cheap_shop = Shop();
        double cheap_price = std::numeric_limits<double>::max();
        double full_price = 0;
        for (auto & it : shops) {
            for (auto & item : it.GetShipment()) {
                for (auto & good : parties) {
                    if (good.Get_Good().Get_UUID() == item.Get_Good().Get_UUID() && item.Get_Price() < cheap_price && item.Get_Amount() >= good.Get_Amount()) {
                        full_price += item.Get_Price() * good.Get_Amount();
                        cheap_shop = it;
                    }
                }
            }
        }
        std::cout << cheap_shop.GetName() << ", Price:" << full_price;
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

