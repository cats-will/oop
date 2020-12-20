#include "Storage.h"


Storage::Storage(const std::string& path) : path(path) {
    const boost::filesystem::path file{path};
    this->size = boost::filesystem::file_size(file);
}

std::string Storage::GetPath() const {
    return path;
}

int Storage::GetSize() const {
    return size;
}