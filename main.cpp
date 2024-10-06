#include "SVO.h"
#include "SVOManager.h"

#include <iostream>

int main() {
    SVO::Manager::SparseVoxelOctreeManager svoManager;

    svoManager.CreateOctree(0, 0);
    svoManager.SetVoxelCall(0, 0, 0);

    return 0;
}
