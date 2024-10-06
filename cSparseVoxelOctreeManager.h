#pragma once
#include "cSparseVoxelOctree.h"

#include <unordered_map>
#include <string>

namespace SVO {
    namespace Manager {
        class cSparseVoxelOctreeManager {
            std::unordered_map<std::string, SVO::Octree::cSparseVoxelOctree*> mUnorderedMap;

        public:
            void CreateOctree(const int& octreeLocalX, const int& octreeLocalY);
            void DeleteOctree(const int& octreeLocalX, const int& octreeLocalY);

            void SetAllVoxels(const int& voxelWorldX, const int& voxelWorldY);
            void SetVoxelCall(const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ);
            void IsVoxelSetCall(const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ);

        private:
            std::string GetOctreeKey(const int& octreeLocalX, const int& octreeLocalY);
        };
    }
}