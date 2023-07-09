#include "BaseBlocksReader.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <experimental/filesystem>
#include <experimental/bits/fs_ops.h>
#include <thread>

namespace fs = std::experimental::filesystem;
using namespace this_thread;
using namespace chrono_literals;
using std::chrono::system_clock;

BaseBlocksReader::BaseBlocksReader()
{

}

void BaseBlocksReader::pushBlock(const string &block)
{
    sleep_until(system_clock::now() + 1s);

    _blocks.push(block);

    if (_blocks.size() == 1)
    {
        _firstBlockTime = sc::system_clock::now();
    }

    if (isEndOfBlocks())
    {
        flushBlocks();
    }
}

void BaseBlocksReader::flushBlocks()
{
    if (_blocks.empty())
    {
        return;
    }

    cout << "bulk:";

    stringstream filename;
    auto timeT = sc::system_clock::to_time_t(_firstBlockTime);
    std::tm tm = *std::localtime(&timeT);
    int ms = sc::duration_cast<sc::milliseconds>(_firstBlockTime.time_since_epoch()).count() % 1000;
    filename << put_time(&tm, "%H%M%S") << ms << ".log";

    fs::path logFile{"./logs/" + filename.str()};

    if (!fs::exists(logFile.parent_path()))
    {
        fs::create_directory(logFile.parent_path());
    }

    ofstream file(logFile.relative_path().string());

    while (!_blocks.empty())
    {
        cout << " " << _blocks.front();
        file << _blocks.front();

        _blocks.pop();

        if (!_blocks.empty())
        {
            cout << ",";
            file << ", ";
        }
    }

    cout << endl;

    file.flush();
    file.close();
}
