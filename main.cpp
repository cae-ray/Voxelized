#include "cSparseVoxelOctree.h"

#include <iostream>

int main() {
	cSparseVoxelOctree svo;

	svo.SetAllVoxels();

    // Debug
    std::cout << "Voxel (3, 2, 1) set: "    << svo.IsVoxelSet( 3,  2,  1) << "\n";
    std::cout << "Voxel (7, 7, 7) set: "    << svo.IsVoxelSet( 7,  7,  7) << "\n";
    std::cout << "Voxel (15, 15, 15) set: " << svo.IsVoxelSet(15, 15, 15) << "\n";
    std::cout << "Voxel (15, 15, 15) set: " << svo.IsVoxelSet(15, 15, 15) << "\n";

    return 0;
}
