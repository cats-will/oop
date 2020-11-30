#include <iostream>
#include "Backup.h"


int main( ) {


    Storage storage = {"/home/catswill/lab2/v.sh"};
    std::cout << storage.GetSize() << '\n';
    std::cout << storage.GetPath();


}