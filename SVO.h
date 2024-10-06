#pragma once
#include "Bitset.h"
#include "OctreeSettings.h"

namespace SVO {
    namespace Octree {
        struct OctreeNode {
            Math::BitSet mVoxelMask;
            OctreeNode*  mChildren[nodeChildren];

            // mChildren is initialized to null in constructor and deleted in destructor
            OctreeNode();
            ~OctreeNode();

            // If no bits are set, it's a leaf node (no children)
            bool IsLeaf() const { return mVoxelMask.None(); };
        };

        class SparseVoxelOctree {
        public:
            int mOctreeLocalX;
            int mOctreeLocalY;

            SparseVoxelOctree(const int& octreeLocalX, const int& octreeLocalY);
            ~SparseVoxelOctree() { delete mRoot; };

            void SetAllVoxels();
            void SetVoxel  (const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ) {        SetVoxelRecursive  (mRoot, voxelWorldX, voxelWorldY, voxelWorldZ, 0); };
            bool IsVoxelSet(const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ) { return IsVoxelSetRecursive(mRoot, voxelWorldX, voxelWorldY, voxelWorldZ, 0); };

        private:
            OctreeNode* mRoot;

            void SetVoxelRecursive  (      OctreeNode* node,        const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ, const int& depth);
            bool IsVoxelSetRecursive(const OctreeNode* node,        const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ, const int& depth);
            int  GetChildIndex      (const int&        voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ, const int& depth);
        };
    }
}
