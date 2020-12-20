#include "DeltaRestorePoint.h"


DeltaRestorePoint::DeltaRestorePoint(Storage restore_point) : delta_restore_point(restore_point) {}

void DeltaRestorePoint::SharedStorageAlgorithm() {

}

void DeltaRestorePoint::FullStorageAlgorithm() {

}

Storage DeltaRestorePoint::GetDelta() {
    return delta_restore_point;
}

std::ostream& operator<<(std::ostream& out, DeltaRestorePoint &point) {
    return out << "Path:" << point.GetDelta().GetPath() << "   Size:" << point.GetDelta().GetSize() << '\n';
}

int DeltaRestorePoint::GetFullSize() {
    return delta_restore_point.GetSize();
}




















