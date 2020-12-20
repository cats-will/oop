#pragma once

#include "IRestorePoint.h"

class DeltaRestorePoint : public IRestorePoint {
    Storage delta_restore_point;
public:
    DeltaRestorePoint() = default;

    DeltaRestorePoint(Storage restore_point);

    void SharedStorageAlgorithm();

    void FullStorageAlgorithm();

    Storage GetDelta();

    int GetFullSize() override;

    friend std::ostream& operator<<(std::ostream& out, DeltaRestorePoint &point);
};





























