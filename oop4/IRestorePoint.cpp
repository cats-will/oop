#include "IRestorePoint.h"


void IRestorePoint::AddFile(std::list<Storage> restore_points, const Storage& file) {
    restore_points.push_back(file);
}

void IRestorePoint::RemoveFile(std::list<Storage> restore_points, const Storage& file) {
    for (auto &it : restore_points) {
       if (it.GetPath() == file.GetPath()) {
           //restore_points.erase(restore_points.cbegin() + it);
       }
    }
}
