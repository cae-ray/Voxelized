#include "cSparseVoxelOctree.h"
#include "cSparseVoxelOctreeManager.h"

#include <iostream>

int main() {
    cSparseVoxelOctreeManager svoManager;

    svoManager.CreateOctree(0, 0);
    svoManager.SetVoxelCall(0, 0, 0);

    return 0;
}
