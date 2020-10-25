#pragma  once

#include "Shipment.h"

class Shop {
private:
    std::string shop_name_;
    Shipment item_;
public:
    Shop() = default;

    Shop(std::string shop_name, Shipment item) : shop_name_(shop_name), item_(item) {}

    friend std::ostream& operator<<(std::ostream& out, Shop &shop) {
        out << "Shop_name:" << shop.shop_name_ << ", Item:" << shop.item_.Get_Good().Get_Name() << ", UUID:" << shop.item_.Get_Good().Get_UUID();
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


