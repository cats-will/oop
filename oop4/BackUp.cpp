#include "BackUp.h"


BackUp::BackUp(std::list<IRestorePoint *> rp) : rp(rp) {}

boost::uuids::uuid BackUp::GetUUID() const {
    return UUID;
}

boost::posix_time::ptime BackUp::GetCreationTime() const {
    return CreationTime;
}

int BackUp::GetSize() const {
    int size = 0;

    for (auto &it : rp) {
        size += it->GetFullSize();
    }
    return size;
}























