#include <iostream>

#include "BackUp.h"

int main() {
/*
    RP_Creator* creator = new Full_RP_Creator();

    RP_Creator* creator2 = new Delta_RP_Creator();

    std::list<IRestorePoint*> rp;
    rp.push_back(reinterpret_cast<IRestorePoint *const>(creator2));
    rp.push_back(reinterpret_cast<IRestorePoint *const>(creator));

    BackUp backUp = {rp};
    std::cout << backUp.GetCreationTime();
*/
    Storage storage = {"/home/catswill/lab2/v.sh"};
    FullRestorePoint fullRestorePoint = {storage};

}













































