#include "SVOManager.h"

namespace SVO {
	namespace Manager {
		void SparseVoxelOctreeManager::CreateOctree(const int& octreeLocalX, const int& octreeLocalY) {
			SVO::Octree::SparseVoxelOctree* newOctree = new SVO::Octree::SparseVoxelOctree(octreeLocalX, octreeLocalY);

			mUnorderedMap[GetOctreeKey(octreeLocalX, octreeLocalY)] = newOctree;
		}

		void SparseVoxelOctreeManager::DeleteOctree(const int& octreeLocalX, const int& octreeLocalY) {
			std::uint64_t key = GetOctreeKey(octreeLocalX, octreeLocalY);

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

		std::int64_t SparseVoxelOctreeManager::GetOctreeKey(const int& octreeLocalX, const int& octreeLocalY) {
			return (static_cast<std::int64_t>(octreeLocalX) << 32) | (static_cast<std::int64_t>(octreeLocalX) & 0xFFFFFFFF);	// Arvid's code, ask him if it breaks lmao
		}
	}
}
