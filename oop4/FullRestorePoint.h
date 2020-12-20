#pragma once
#include "IRestorePoint.h"

class FullRestorePoint : public IRestorePoint {
    Storage full_restore_point;
public:
    //FullRestorePoint() = default;

    FullRestorePoint(Storage restore_point);

    void SharedStorageAlgorithm() override;

    void FullStorageAlgorithm() override;

    Storage GetFull();

    int GetFullSize() override;

    friend std::ostream& operator<<(std::ostream& out, FullRestorePoint &point);
};




















