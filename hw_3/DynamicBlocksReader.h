#ifndef DYNAMICBLOCKSREADER_H
#define DYNAMICBLOCKSREADER_H

#include "BaseBlocksReader.h"

class DynamicBlocksReader : public BaseBlocksReader
{
public:
    DynamicBlocksReader() = default;

protected:
    bool isEndOfBlocks() const override;
};

#endif // DYNAMICBLOCKSREADER_H
