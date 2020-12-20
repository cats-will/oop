#pragma once

#include <utility>

#include "Storage.h"
#include "IRestorePoint.h"

class BackUp {
    boost::uuids::uuid UUID;
    boost::posix_time::ptime CreationTime = boost::posix_time::second_clock::local_time();
    std::list<IRestorePoint *> rp;
    int size;
public:
    BackUp() = default;

    BackUp(std::list<IRestorePoint *> rp);

    boost::uuids::uuid GetUUID() const;

    boost::posix_time::ptime GetCreationTime() const;

    int GetSize() const;
};


























