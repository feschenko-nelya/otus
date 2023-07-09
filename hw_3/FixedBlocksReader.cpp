#include "FixedBlocksReader.h"
#include <cmath>
#include <iostream>
#include <stdexcept>

FixedBlocksReader::FixedBlocksReader(short N)
            :_N(std::abs(N))
{
}

bool FixedBlocksReader::isEndOfBlocks() const
{
    return _blocks.size() == _N;
}
