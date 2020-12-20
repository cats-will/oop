#include "FullRestorePoint.h"


FullRestorePoint::FullRestorePoint(Storage restore_point) : full_restore_point(restore_point) {}

void FullRestorePoint::SharedStorageAlgorithm() {
    //реализуем раздельное хранение - файлы копируются в специальную папку и хранятся там раздельно.
}

void FullRestorePoint::FullStorageAlgorithm() {
    //реализуем общее хранение - все указанные в бекапе объекты складываются в один архив.
}

Storage FullRestorePoint::GetFull() {
    return full_restore_point;
}

std::ostream& operator<<(std::ostream& out, FullRestorePoint &point) {
    return out << "Path:" << point.GetFull().GetPath() << "   Size:" << point.GetFull().GetSize() << '\n';
}

int FullRestorePoint::GetFullSize() {
    return full_restore_point.GetSize();
}




















