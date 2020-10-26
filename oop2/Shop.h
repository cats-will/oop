#pragma  once

#include "Shipment.h"

class Shop {
private:
    int id_;
    std::string shop_name_;
    std::list<Shipment> item_;
public:
    Shop() = default;

    Shop(int id, std::string shop_name, std::list<Shipment> item) : id_(id), shop_name_(shop_name), item_(item) {}

    friend std::ostream& operator<<(std::ostream& out, Shop &shop) {
        out << "Shop's name:" << shop.shop_name_ << ", ID:" << shop.id_ << '\n';
        for (auto & it : shop.item_) {
            out << "Item:" << it.Get_Good().Get_Name();
            out << ", UUID:" << it.Get_Good().Get_UUID();
            out << ", Price:" << it.Get_Price();
            out << ", Amount:" << it.Get_Amount() << '\n';
        }
        return  out;
    }

    void change_price(Shop &shop, int id, double price) {
        for(auto & it : shop.item_) {
            if(it.Get_Good().Get_UUID() == id) {
                it.Set_Price(price);
            }
        }
    }

    void add_to_shop(Shipment &item) {
        for (auto & it : item_) {
            if(it.Get_Good().Get_UUID() == item.Get_Good().Get_UUID()) {
                it.Get_Amount() += item.Get_Amount();
            }
            else {
                item_.push_back(item);
            }
        }
    }

    void find_the_cheapest(std::list<Shop> &shops, int UUID) {

        for(auto & it : shops) {
            for(auto & it2 : it.item_) {
                if(it2.Get_Good().Get_UUID() == UUID) {
                    if()
                }
            }
        }
    }

};

/*
    Shop(std::map <std::string, Good> &shop_) {
        for (auto it = shop_.begin(); it != shop_.end(); ++it) {
            shop.emplace(it->first, it->second);
        }
    }

    void add_to_shop(const Good &gd) {
        for(auto &it : shop) {
            if(it.second.UUID_ == gd.UUID_) {
                it.second.amount_ += gd.amount_;
            }
            else {
                shop.insert(std::pair<std::string, Good>(it.first, gd));
            }
        }
    }

    f
        for (auto it = shop1.shop.begin(); it != shop1.shop.end(); ++it) {
            out << it->first << ", " << it->second << '\n';
        }
        return out;
    }


    friend std::ostream &operator<<(std::ostream &out, Shop &shop1) {
        out << shop1.shop_name << ' ';
        for (int i = 0; i < shop1.item.size(); ++i) {
            out << shop1.item[i] << ',';
        }
    }

*/


