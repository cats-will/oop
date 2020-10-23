#pragma  once

#include "Good.h"

class Shop : protected Good {
    std::map <std::string, Good> shop;
public:
    Shop(std::map <std::string, Good> &shop_) {
        for (auto it = shop_.begin(); it != shop_.end(); ++it) {
            shop.emplace(it->first, it->second);
        }
    }

    void add_to_shop(Shop &shop1, Good &gd) {
        for(auto &it : shop1.shop) {
            if(it.second.UUID_ == gd.UUID_) {

            }

        }
    }

    friend std::ostream& operator<<(std::ostream& out, Shop &shop1) {
        for (auto & it : shop1.shop) {
            out << it.first << ", " << it.second << '\n';
        }
        return out;
    }



};


