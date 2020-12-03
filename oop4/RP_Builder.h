#pragma once

#include <list>

class RestorePoint;
class Storage;

class RP_Builder {
public:
    virtual void CreateRestorePoint() = 0;

    void AddFile(std::list<Storage> restore_points, const Storage& file) {
        restore_points.push_back(file);
    }

    void RemoveFile(std::list<Storage> restore_points, const Storage& file) {
        restore_points.remove(file);
    }

    virtual void SharedStorageAlgorithm() = 0;

    virtual void FullStorageAlgorithm() = 0;

};