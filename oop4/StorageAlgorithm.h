#pragma once

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
    Storage(const std::string& path) : path(path) {
        const boost::filesystem::path file{path};
        this->size = boost::filesystem::file_size(file);
    }

    std::string GetPath() const {
        return path;
    }

    int GetSize() const {
        return size;
    }
};
