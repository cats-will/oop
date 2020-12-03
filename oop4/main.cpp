#include <iostream>
#include "Backup.h"


int main( ) {

    Storage storage = {"/home/catswill/lab2/v.sh"};
    std::cout << storage.GetSize() << '\n';
    std::cout << storage.GetPath();

    std::list<Storage> rp1;
    rp1.push_back(storage);

    RestorePoint restorePoint = {rp1};
    std::cout << restorePoint << '\n';

    Backup backup = {restorePoint};

    std::cout << backup.GetUUID() << ' ' << backup.GetCreationTime() << '\n';


}