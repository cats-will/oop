#pragma once

#include "Storage.h"


class IRestorePoint {
public:
    virtual void SharedStorageAlgorithm() = 0;

    virtual void FullStorageAlgorithm() = 0;

    virtual int GetFullSize() = 0;

    void AddFile(std::list<Storage> restore_points, const Storage& file);

    void RemoveFile(std::list<Storage> restore_points, const Storage& file);


};






















