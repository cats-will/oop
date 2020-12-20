#pragma once

#include "FullRestorePoint.h"
#include "DeltaRestorePoint.h"

#include <string>
#include <list>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

#include "boost/date_time/posix_time/posix_time.hpp"

#include <boost/filesystem.hpp>


class Storage {
    std::string path;
    int size;
public:
    Storage(const std::string& path);

    std::string GetPath() const;

    int GetSize() const;
};
