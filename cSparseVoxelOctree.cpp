#include "cSparseVoxelOctree.h"

// Octree node
////////////////////////////////////////////////////////////////
sOctreeNode::sOctreeNode() {
    for (int i = 0; i < nodeChildren; ++i) {
        mChildren[i] = nullptr;
    }
}

sOctreeNode::~sOctreeNode() {
    for (int i = 0; i < nodeChildren; ++i) {
        delete mChildren[i];
    }
}
////////////////////////////////////////////////////////////////
// Octree node

// Sparse voxel octree
////////////////////////////////////////////////////////////////
void cSparseVoxelOctree::SetAllVoxels() {
    for (int x = 0; x < octreeSize; ++x) {
        for (int y = 0; y < octreeSize; ++y) {
            for (int z = 0; z < octreeSize; ++z) {
                SetVoxel(x, y, z);
            }
        }
    }
}

void cSparseVoxelOctree::SetVoxelRecursive(sOctreeNode* node, const int& x, const int& y, const int& z, const int& depth) {
    if (depth == maxDepth) {
        return; // We reached the max depth, don't subdivide further
    }

    int index = GetChildIndex(x, y, z, depth);
    if (!node->mChildren[index]) {
        node->mChildren[index] = new sOctreeNode();
        node->mVoxelMask.Set(index);    // Mark the child as active
    }

    SetVoxelRecursive(node->mChildren[index], x, y, z, depth + 1);
}

bool cSparseVoxelOctree::IsVoxelSetRecursive(const sOctreeNode* node, const int& x, const int& y, const int& z, const int& depth) {
    if (depth == maxDepth) {
        return true;    // We've reached the max depth, so the voxel is set
    }

    int index = GetChildIndex(x, y, z, depth);
    if (!node->mChildren[index]) {
        return false;   // No child at this index, voxel is not set
    }

    return IsVoxelSetRecursive(node->mChildren[index], x, y, z, depth + 1);
}

int cSparseVoxelOctree::GetChildIndex(const int& x, const int& y, const int& z, const int& depth) {
    int shift = maxDepth - depth - 1;   // Shift for the current depth
    int xi = (x >> shift) & 1;          // X bit for the current depth
    int yi = (y >> shift) & 1;          // Y bit for the current depth
    int zi = (z >> shift) & 1;          // Z bit for the current depth

    return (xi << 2) | (yi << 1) | zi;
}
////////////////////////////////////////////////////////////////
// Sparse voxel octree 
