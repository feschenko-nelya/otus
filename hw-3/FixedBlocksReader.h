#ifndef FIXEDBLOCKSREADER_H
#define FIXEDBLOCKSREADER_H
#include "BaseBlocksReader.h"

class FixedBlocksReader : public BaseBlocksReader
{
public:
    FixedBlocksReader(short N);

protected:
    bool isEndOfBlocks() const override;
private:
    short _N = 0;

};

#endif // FIXEDBLOCKSREADER_H
