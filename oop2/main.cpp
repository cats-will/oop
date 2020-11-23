#include "Shop.h"
#include "Facade.h"


int main() {

    //Shop a = create();

    Facade a;
    Shop meh;

    Good skirt = {"blue skirt"};
    Good sweater = {"sweater"};
    Good suit = {"suit"};
    Good blouse = {"blouse"};

    std::list<Good> parties;

    parties.push_back(skirt);
//    parties.push_back(sweater);
//    parties.push_back(suit);
//    parties.push_back(blouse);


    Shipment party_1 = {sweater, 500, 10};
    Shipment party_2 = {skirt, 800, 13};
    Shipment party_3 = {suit, 1600, 13};
    Shipment party_4 = {skirt, 300, 13};
    Shipment party_5 = {blouse, 6300, 13};
    Shipment party_6 = {skirt, 3600, 13};

    std::list<Shipment> cheap_party;
    cheap_party.push_back(party_2);

    std::list<Shipment> Bershka_items;
    Bershka_items.push_back(party_2);
    Bershka_items.push_back(party_1);
    Bershka_items.push_back(party_5);
    Bershka_items.push_back(party_3);

    std::list<Shipment> Sale_items;
    Sale_items.push_back(party_3);
    Sale_items.push_back(party_4);
    Sale_items.push_back(party_5);
    Sale_items.push_back(party_1);

    std::list<Shipment> Topman_items;
    Topman_items.push_back(party_6);
    Topman_items.push_back(party_1);
    Topman_items.push_back(party_3);
    Topman_items.push_back(party_5);


    Shop Bershka = {1, "Bershka", Bershka_items};
    Shop Sale = {2, "Sale", Sale_items};
    Shop Topman = {3, "Topman", Topman_items};

    std::list<Shop> shops;

    shops.push_back(Bershka);
    shops.push_back(Sale);
    shops.push_back(Topman);

//    a.find_the_cheapest_party(shops, cheap_party);



    int money = 2000;
    a.buy_a_party(Bershka, parties, 3);

//    for (auto  &item : Bershka_items) {
//        std:: cout << ' ' << item.Get_Amount();
//    }

/*
 * find_the_cheapest is correct
    std::list<Shop> Shops;

    Shops.push_back(Bershka);
    Shops.push_back(Sale);
    Shops.push_back(Topman);

    a.find_the_cheapest(Shops, skirt);
*/

/*
    Bershka.add_to_shop(party_2);
    std::cout << Bershka;
    Bershka.change_price(Bershka, 1, 500);
    std::cout << Bershka;
    */

/*
    std::cout << "If you want to add a shipment to the shop write \"add\"\n";
    std::string var;
    std::cin >> var;
      if(var == "add") {
        add(a);
    }
*/

/*
    Facade a;

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
