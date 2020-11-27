#pragma once

#include "StorageAlgorithm.h"

class RestorePoint {
    std::list<Storage> restore_points;
public:

    explicit RestorePoint(std::list<Storage> restore_points) : restore_points(std::move(restore_points)) {}

    void AddFile(const Storage& file) {
        restore_points.push_back(file);
    }

    void RemoveFile(const Storage& file) {
        restore_points.emplace_back(file);
        restore_points.pop_back();
    }

    friend std::ostream& operator<<(std::ostream& out, RestorePoint &point) {
        for (auto &it : point.restore_points) {
            out << "Path:" << it.GetPath() << "; Size:" << it.GetSize() << '\n';
        }
        return out;
    }
};
