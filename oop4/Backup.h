#pragma once

#include <utility>

#include "RestorePoint.h"

class Backup {
    boost::uuids::uuid UUID;
    boost::posix_time::ptime CreationTime = boost::posix_time::second_clock::local_time();
    RestorePoint Restore_Points;
    int size;
public:
    Backup() = default;

    Backup(RestorePoint Restore_Point) : Restore_Points(Restore_Point) {}

    boost::uuids::uuid GetUUID() const {
        return UUID;
    }

    boost::posix_time::ptime GetCreationTime() const {
        return CreationTime;
    }










};