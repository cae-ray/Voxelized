#include "cSparseVoxelOctreeManager.h"

// Octree creation and deletion
////////////////////////////////////////////////////////////////
void cSparseVoxelOctreeManager::CreateOctree(const int& octreeLocalX, const int& octreeLocalY) {
	cSparseVoxelOctree* newOctree = new cSparseVoxelOctree(octreeLocalX, octreeLocalY);

	mUnorderedMap[GetOctreeKey(octreeLocalX, octreeLocalY)] = newOctree;
}

void cSparseVoxelOctreeManager::DeleteOctree(const int& octreeLocalX, const int& octreeLocalY) {
	delete(mUnorderedMap[GetOctreeKey(octreeLocalX, octreeLocalY)]);
	mUnorderedMap.erase (GetOctreeKey(octreeLocalX, octreeLocalY));
}
////////////////////////////////////////////////////////////////
// Octree creation and deletion

// Voxel manipulation passthrough
////////////////////////////////////////////////////////////////
void cSparseVoxelOctreeManager::SetAllVoxels(const int& voxelWorldX, const int& voxelWorldY) {
	mUnorderedMap[GetOctreeKey(voxelWorldX, voxelWorldY)]->SetAllVoxels();
}
void cSparseVoxelOctreeManager::SetVoxelCall(const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ) {
	mUnorderedMap[GetOctreeKey(voxelWorldX, voxelWorldY)]->SetVoxel(voxelWorldX, voxelWorldY, voxelWorldZ);
}
void cSparseVoxelOctreeManager::IsVoxelSetCall(const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ) {
	mUnorderedMap[GetOctreeKey(voxelWorldX, voxelWorldY)]->IsVoxelSet(voxelWorldX, voxelWorldY, voxelWorldZ);
}
////////////////////////////////////////////////////////////////
// Voxel manipulation passthrough

// Helper functions
////////////////////////////////////////////////////////////////
std::string cSparseVoxelOctreeManager::GetOctreeKey(const int& octreeLocalX, const int& octreeLocalY) {
	return std::to_string(octreeLocalX) + " " + std::to_string(octreeLocalY);
}
////////////////////////////////////////////////////////////////
// Helper functions
