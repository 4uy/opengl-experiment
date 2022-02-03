#pragma once

#include <array>

#include "../world/block.h"

struct Chunk {
    std::array<Block, 65536> blocks;
};
