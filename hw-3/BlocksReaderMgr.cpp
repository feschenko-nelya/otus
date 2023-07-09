#include "BlocksReaderMgr.h"
#include "DynamicBlocksReader.h"
#include "FixedBlocksReader.h"

BlocksReaderMgr::BlocksReaderMgr(int fixedBlocksCount)
                :_fixedBlocksCount(fixedBlocksCount)
{
    _reader.reset(new FixedBlocksReader(_fixedBlocksCount));
}

void BlocksReaderMgr::read(const string &cmd)
{
    if (cmd.compare("{") == 0)
    {
        if (_isDynamicReading)
        {
            return;
        }

        _isDynamicReading = true;
        _reader->flushBlocks();

        if (dynamic_cast<FixedBlocksReader *>(_reader.get()))
        {
            _reader.reset(new DynamicBlocksReader());
        }

        return;
    }
    else if (cmd.compare("}") == 0)
    {
        if (_isDynamicReading)
        {
            _reader->flushBlocks();
            _reader.reset(new FixedBlocksReader(_fixedBlocksCount));

            _isDynamicReading = false;

            return;
        }
    }

    if (_isDynamicReading)
    {
        if (dynamic_cast<FixedBlocksReader *>(_reader.get()))
        {
            _reader->flushBlocks();
            _reader.reset(new DynamicBlocksReader());
        }

    }

    _reader->pushBlock(cmd);
}

void BlocksReaderMgr::flush()
{
    if (dynamic_cast<FixedBlocksReader *>(_reader.get()))
    {
        _reader->flushBlocks();
    }
}
