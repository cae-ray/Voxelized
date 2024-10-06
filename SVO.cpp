#include "SVO.h"

namespace SVO {
    namespace Octree {
        OctreeNode::OctreeNode() {
            for (int i = 0; i < nodeChildren; ++i) {
                mChildren[i] = nullptr;
            }
        }

        OctreeNode::~OctreeNode() {
            for (int i = 0; i < nodeChildren; ++i) {
                delete mChildren[i];
            }
        }

        SparseVoxelOctree::SparseVoxelOctree(const int& octreeLocalX, const int& octreeLocalY) {
            mRoot = new OctreeNode();
            mOctreeLocalX = octreeLocalX;
            mOctreeLocalY = octreeLocalY;
        }

        void SparseVoxelOctree::SetAllVoxels() {
            for (int x = 0; x < octreeSize; ++x) {
                for (int y = 0; y < octreeSize; ++y) {
                    for (int z = 0; z < octreeSize; ++z) {
                        SetVoxel(x, y, z);
                    }
                }
            }
        }

        void SparseVoxelOctree::SetVoxelRecursive(OctreeNode* node, const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ, const int& depth) {
            if (depth == maxDepth) {
                return; // We reached the max depth, don't subdivide further
            }

            int index = GetChildIndex(voxelWorldX, voxelWorldY, voxelWorldZ, depth);
            if (!node->mChildren[index]) {
                node->mChildren[index] = new OctreeNode();
                node->mVoxelMask.Set(index);    // Mark the child as active
            }

            SetVoxelRecursive(node->mChildren[index], voxelWorldX, voxelWorldY, voxelWorldZ, depth + 1);
        }

        bool SparseVoxelOctree::IsVoxelSetRecursive(const OctreeNode* node, const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ, const int& depth) {
            if (depth == maxDepth) {
                return true;    // We've reached the max depth, so the voxel is set
            }

            int index = GetChildIndex(voxelWorldX, voxelWorldY, voxelWorldZ, depth);
            if (!node->mChildren[index]) {
                return false;   // No child at this index, voxel is not set
            }

            return IsVoxelSetRecursive(node->mChildren[index], voxelWorldX, voxelWorldY, voxelWorldZ, depth + 1);
        }

        int SparseVoxelOctree::GetChildIndex(const int& voxelWorldX, const int& voxelWorldY, const int& voxelWorldZ, const int& depth) {
            int shift = maxDepth - depth - 1;   // Shift for the current depth
            int xi = (voxelWorldX >> shift) & 1;          // X bit for the current depth
            int yi = (voxelWorldY >> shift) & 1;          // Y bit for the current depth
            int zi = (voxelWorldZ >> shift) & 1;          // Z bit for the current depth

            return (xi << 2) | (yi << 1) | zi;
        }
    }
}
