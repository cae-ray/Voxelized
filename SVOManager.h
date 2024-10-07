#pragma once
#include "SVO.h"

#include <unordered_map>
#include <string>

namespace SVO {
    namespace Manager {
        class SparseVoxelOctreeManager {
            std::unordered_map<std::int64_t, SVO::Octree::SparseVoxelOctree*> mUnorderedMap;

        public:
            void CreateOctree(const int& octreeLocalX, const int& octreeLocalY);
            void DeleteOctree(const int& octreeLocalX, const int& octreeLocalY);

            void SetAllVoxels  (const int& voxelWorldX, const int& voxelWorldY);
            void SetVoxelCall  (const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ);
            void IsVoxelSetCall(const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ);

        private:
            std::int64_t GetOctreeKey(const int& octreeLocalX, const int& octreeLocalY);
        };
    }
}