#pragma once

#include <cstdint>

enum class BlockType : std::uint8_t {
    AIR,
    GRASS
};

struct Block {
    BlockType type;
};
