#include "Shop.h"
#include "Facade.h"

int main() {

    Facade a;

    Good skirt = a.CreateGood(1, "blue skirt");

    Shipment party_1 = a.CreateShipment(skirt, 800, 15);

    Shop Bershka = a.CreateShop("Bershka", party_1);



/*
    Good a = {12, "blue skirt", 123.3, 4};

    Good c = {12, "blue skirt", 123.3, 4};

    Good b = {11, "green skirt", 123.3, 4};

    std::map<std::string, Good> Bershka;
    Bershka.emplace("Bershka", a);
    Shop g = {Bershka};

    g.add_to_shop(c);
    g.add_to_shop(c);

    std::cout << g;

    std::vector<Good> items;
    items.push_back(a);
    items.push_back(c);
    items.push_back(b);
    Shop shop = {"Bershka", items};

    std::cout << shop;
*/

}
