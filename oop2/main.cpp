#include "Shop.h"

int main() {
    Good a = {12, "blue skirt", 123.3, 4};
    std::map<std::string, Good> Bershka;
    Bershka.emplace("Bershka", a);
    Shop g = {Bershka};
    std::cout << g;
    return 0;
}
