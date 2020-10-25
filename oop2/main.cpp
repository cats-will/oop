#include "Shop.h"
#include "Facade.h"


int main() {
    //Shop a = create();

    std::cout << "If you want to add a shipment to the shop write \"add\"\n";
    std::string var;
    std::cin >> var;
    /*  if(var == "add") {
        add(a);
    }
    */

/*
    Facade a;

    Good skirt = a.CreateGood(1, "blue skirt");
    Good skirt1 = a.CreateGood(12, "green skirt");

    std::list<Shipment> party_1 = a.CreateShipment_as_list(skirt, 800, 15);
    Shipment party_2 = a.CreateShipment(skirt, 800, 13);
    Shipment party_3 = a.CreateShipment(skirt1, 800, 13);

    Shop Bershka = a.CreateShop(1, "Bershka", party_1);

    Bershka.add_to_shop(party_2);
    Bershka.add_to_shop(party_3);
    //a.add_shipments_from_file(Bershka);

    a.ShowShop(Bershka);
*/
}
