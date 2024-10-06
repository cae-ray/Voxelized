#pragma once
#include "cBitset.h"
#include "octreeSettings.h"

namespace SVO {
    namespace Octree {
        struct sOctreeNode {
            cBitSet      mVoxelMask;
            sOctreeNode* mChildren[nodeChildren];

            // mChildren is initialized to null in constructor and deleted in destructor
            sOctreeNode();
            ~sOctreeNode();

            // If no bits are set, it's a leaf node (no children)
            bool IsLeaf() const { return mVoxelMask.None(); };
        };

        class cSparseVoxelOctree
        {
        public:
            int mOctreeLocalX;
            int mOctreeLocalY;

            cSparseVoxelOctree(const int& octreeLocalX, const int& octreeLocalY);
            ~cSparseVoxelOctree() { delete mRoot; };

            void SetAllVoxels();
            void SetVoxel(const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ) { SetVoxelRecursive(mRoot, voxelWorldX, voxelWorldY, voxelWorldZ, 0); };
            bool IsVoxelSet(const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ) { return IsVoxelSetRecursive(mRoot, voxelWorldX, voxelWorldY, voxelWorldZ, 0); };

        private:
            sOctreeNode* mRoot;

            void SetVoxelRecursive(sOctreeNode* node, const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ, const int& depth);
            bool IsVoxelSetRecursive(const sOctreeNode* node, const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ, const int& depth);
            int  GetChildIndex(const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ, const int& depth);
        };
    }
}
