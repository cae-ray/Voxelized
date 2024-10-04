#pragma once
#include "cBitset.h"
#include "octreeSettings.h"

// Octree node
////////////////////////////////////////////////////////////////
struct sOctreeNode {
    cBitSet      mVoxelMask;
    sOctreeNode* mChildren[nodeChildren];

    // mChildren is initialized to null in constructor and deleted in destructor
     sOctreeNode();
    ~sOctreeNode();

    // If no bits are set, it's a leaf node (no children)
    bool IsLeaf() const { return mVoxelMask.None(); };
};
////////////////////////////////////////////////////////////////
// Octree node

// Sparse voxel octree
////////////////////////////////////////////////////////////////
class cSparseVoxelOctree
{
public:
    int octreePosition[2];

     cSparseVoxelOctree(const int& inputX, const int& inputY);
    ~cSparseVoxelOctree() { delete mRoot; };
    
    void SetAllVoxels();
    void SetVoxel    (int& x, int& y, int& z) { SetVoxelRecursive         (mRoot, x, y, z, 0); };
    bool IsVoxelSet  (int& x, int& y, int& z) { return IsVoxelSetRecursive(mRoot, x, y, z, 0); };

    // TODO store world coordinates divided by octreeSize to allow multiple octrees to exist in the world

private:
    sOctreeNode* mRoot;

    void SetVoxelRecursive  (      sOctreeNode* node, const int& x, const int& y, const int& z, const int& depth);
    bool IsVoxelSetRecursive(const sOctreeNode* node, const int& x, const int& y, const int& z, const int& depth);
    int  GetChildIndex      (                         const int& x, const int& y, const int& z, const int& depth);

};
////////////////////////////////////////////////////////////////
// Sparse voxel octree 
