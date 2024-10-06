#pragma once
#include "octreeSettings.h"

// Custom bitset class for 8 bits
class BitSet {
    unsigned char mBits;    // Storage for 8 bits

public:
    BitSet() : mBits(0) {}

    // Set a specific bit
    void Set(int index) {
        mBits |= (1 << index);
    }

    // Check if a specific bit is set
    bool IsSet(int index) const {
        return (mBits & (1 << index)) != 0;
    }

    // Clear all bits
    void Reset() {
        mBits = 0;
    }

    // Check if all bits are set
    bool All() const {
        return mBits == (1 << nodeChildren) - 1;    // (1 << 8) = 1 * 2 ^ 8 = 256, - 1 = 255
    }

    // Check if all bits are unset
    bool None() const {
        return mBits == 0;
    }
};
