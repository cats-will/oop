#pragma once

#include "RestorePoint.h"

class Backup {
    boost::uuids::uuid UUID;
    boost::posix_time::ptime CreationTime = boost::posix_time::second_clock::local_time();
   // std::list<RestorePoint *> Restore_Point;
    int size;
public:
    Backup() = default;

    boost::uuids::uuid GetUUID() const {
        return UUID;
    }

    boost::posix_time::ptime GetCreationTime() const {
        return CreationTime;
    }








};