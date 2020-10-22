#include <iostream>
#include <string>
#include <utility>

class Shop {
    int UUID;
    std::string name;
    double price;
    int amount = 0;
public:
    Shop(int UUID_, std::string name_, double price_) : UUID(UUID_), name(std::move(name_)), price(price_) { //мб сломается из-за move
        amount += 1;
    }

    friend std::ostream& operator<<(std::ostream& out, const Shop &shop) {
        return out << shop.name << " {UUID = " << shop.UUID << ", price = " << shop.price << ", amount = " << shop.amount << "}\n";
    }
};

class Good {
    int UUID;
    std::string name;
    double price;
    int amount;
public:

};

class MetaData {

};



int main() {

    Shop a = {1, "asd", 123};
    std::cout << a;
    return 0;
}
