#pragma once

#include "StorageAlgorithm.h"
#include "RP_Builder.h"


class FullRestorePoint : public RP_Builder {
    std::list<Storage> restore_points;
public:

    FullRestorePoint() = default;

    FullRestorePoint(const std::list<Storage> restore_points) : restore_points(restore_points) {}

    void CreateRestorePoint() {
    //создаем полноценную точку восстановления
    }

    void SharedStorageAlgorithm() {
    //реализуем раздельное хранение - файлы копируются в специальную папку и хранятся там раздельно.
    }

    void FullStorageAlgorithm() {
    //реализуем общее хранение - все указанные в бекапе объекты складываются в один архив.
    }

    friend std::ostream& operator<<(std::ostream& out, FullRestorePoint &point) {
        for (auto &it : point.restore_points) {
            out << "Path:" << it.GetPath() << "   Size:" << it.GetSize() << '\n';
        }
        return out;
    }
};


class DeltaRestorePoint : public RP_Builder {
    std::list<Storage> restore_points;
public:

    DeltaRestorePoint() = default;

    DeltaRestorePoint(const std::list<Storage> restore_points) : restore_points(restore_points) {}

    void CreateRestorePoint() {
    //создаем инкремент
    }

    void SharedStorageAlgorithm() {

    }

    void FullStorageAlgorithm() {

    }

    friend std::ostream& operator<<(std::ostream& out, DeltaRestorePoint &point) {
        for (auto &it : point.restore_points) {
            out << "Path:" << it.GetPath() << "   Size:" << it.GetSize() << '\n';
        }
        return out;
    }
};