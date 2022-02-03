#pragma once

#include <array>

#include "../world/block.h"

class Chunk {
public:
    Chunk();
public:
    std::array<Block, 65536> blocks;
};
