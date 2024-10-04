#include "cSparseVoxelOctree.h"
#include "cSparseVoxelOctreeManager.h"

#include <iostream>

int main() {
    cSparseVoxelOctreeManager svoManager;

    int x = 0;
    int y = 0;
    int z = 0;

    svoManager.CreateOctree(x, y);
    svoManager.SetVoxelCall(x, y, z);

	//svo.SetAllVoxels();

    // Debug
    //std::cout << "Voxel (3, 2, 1) set: "    << svo.IsVoxelSet( 3,  2,  1) << "\n";
    //std::cout << "Voxel (7, 7, 7) set: "    << svo.IsVoxelSet( 7,  7,  7) << "\n";
    //std::cout << "Voxel (15, 15, 15) set: " << svo.IsVoxelSet(15, 15, 15) << "\n";
    //std::cout << "Voxel (15, 15, 15) set: " << svo.IsVoxelSet(15, 15, 15) << "\n";

    return 0;
}
