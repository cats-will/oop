#pragma  once

#include "Shipment.h"

class Shop {
private:
    int id_;
    std::string shop_name_;
    std::list<Shipment> item_;
public:
    Shop() = default;

    Shop(int id, std::string shop_name, std::list<Shipment> item) : id_(id), shop_name_(std::move(shop_name)), item_(std::move(item)) {}

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

    void change_price(Shop &shop, boost::uuids::uuid id, double price) {
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

    std::list<Shipment> GetShipment() {
       return item_;
    }

    std::string GetName() {
        return shop_name_;
    }


};




