#pragma once

// Constant settings for the sparse voxel octree
////////////////////////////////////////////////////////////////
constexpr int maxDepth	   = 4;
constexpr int nodeChildren = 8;
constexpr int octreeSize   = 1 << maxDepth;	// Octree size based on depth
////////////////////////////////////////////////////////////////
// Constant settings for the sparse voxel octree
