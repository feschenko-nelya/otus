#ifndef BLOCKSREADERMGR_H
#define BLOCKSREADERMGR_H

#include "BaseBlocksReader.h"
#include <memory>

using namespace std;

class BlocksReaderMgr
{
public:
    BlocksReaderMgr(int fixedBlocksCount);

    void read(const string &cmd);
    void flush();

private:
    unique_ptr<BaseBlocksReader> _reader;
    int _fixedBlocksCount = 0;
    bool _isDynamicReading = false;
};

#endif // BLOCKSREADERMGR_H
