#ifndef BASEBLOCKSREADER_H
#define BASEBLOCKSREADER_H
#include <queue>
#include <string>
#include <chrono>

namespace sc = std::chrono;
using namespace std;

class BaseBlocksReader
{
public:
    BaseBlocksReader();

    void pushBlock(const string &block);
    void flushBlocks();

protected:
    std::queue<string> _blocks;

    virtual bool isEndOfBlocks() const = 0;

private:
    sc::system_clock::time_point _firstBlockTime;

};

#endif // BASEBLOCKSREADER_H
