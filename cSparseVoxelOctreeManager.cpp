#include "cSparseVoxelOctreeManager.h"

namespace SVO {
	namespace Manager {
		void cSparseVoxelOctreeManager::CreateOctree(const int& octreeLocalX, const int& octreeLocalY) {
			SVO::Octree::cSparseVoxelOctree* newOctree = new SVO::Octree::cSparseVoxelOctree(octreeLocalX, octreeLocalY);

			mUnorderedMap[GetOctreeKey(octreeLocalX, octreeLocalY)] = newOctree;
		}

		void cSparseVoxelOctreeManager::DeleteOctree(const int& octreeLocalX, const int& octreeLocalY) {
			std::string key = GetOctreeKey(octreeLocalX, octreeLocalY);

			delete(mUnorderedMap[key]);
			mUnorderedMap.erase(key);
		}

		void cSparseVoxelOctreeManager::SetAllVoxels(const int& voxelWorldX, const int& voxelWorldY) {
			mUnorderedMap[GetOctreeKey(voxelWorldX, voxelWorldY)]->SetAllVoxels();
		}

		void cSparseVoxelOctreeManager::SetVoxelCall(const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ) {
			mUnorderedMap[GetOctreeKey(voxelWorldX, voxelWorldY)]->SetVoxel(voxelWorldX, voxelWorldY, voxelWorldZ);
		}

		void cSparseVoxelOctreeManager::IsVoxelSetCall(const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ) {
			mUnorderedMap[GetOctreeKey(voxelWorldX, voxelWorldY)]->IsVoxelSet(voxelWorldX, voxelWorldY, voxelWorldZ);
		}

		std::string cSparseVoxelOctreeManager::GetOctreeKey(const int& octreeLocalX, const int& octreeLocalY) {
			return std::to_string(octreeLocalX) + " " + std::to_string(octreeLocalY);
		}
	}
}
