#include "SVOManager.h"

namespace SVO {
	namespace Manager {
		void SparseVoxelOctreeManager::CreateOctree(const int& octreeLocalX, const int& octreeLocalY) {
			SVO::Octree::SparseVoxelOctree* newOctree = new SVO::Octree::SparseVoxelOctree(octreeLocalX, octreeLocalY);

			mUnorderedMap[GetOctreeKey(octreeLocalX, octreeLocalY)] = newOctree;
		}

		void SparseVoxelOctreeManager::DeleteOctree(const int& octreeLocalX, const int& octreeLocalY) {
			std::string key = GetOctreeKey(octreeLocalX, octreeLocalY);

			delete(mUnorderedMap[key]);
			mUnorderedMap.erase(key);
		}

		void SparseVoxelOctreeManager::SetAllVoxels(const int& voxelWorldX, const int& voxelWorldY) {
			mUnorderedMap[GetOctreeKey(voxelWorldX, voxelWorldY)]->SetAllVoxels();
		}

		void SparseVoxelOctreeManager::SetVoxelCall(const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ) {
			mUnorderedMap[GetOctreeKey(voxelWorldX, voxelWorldY)]->SetVoxel(voxelWorldX, voxelWorldY, voxelWorldZ);
		}

		void SparseVoxelOctreeManager::IsVoxelSetCall(const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ) {
			mUnorderedMap[GetOctreeKey(voxelWorldX, voxelWorldY)]->IsVoxelSet(voxelWorldX, voxelWorldY, voxelWorldZ);
		}

		std::string SparseVoxelOctreeManager::GetOctreeKey(const int& octreeLocalX, const int& octreeLocalY) {
			return std::to_string(octreeLocalX) + " " + std::to_string(octreeLocalY);
		}
	}
}
