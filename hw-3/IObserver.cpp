#include "IObserver.h"
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

ObserversMgr::ObserversMgr()
{
    _observers.push_back(new ConsoleObserver());
    _observers.push_back(new FileObserver());
}

ObserversMgr::~ObserversMgr()
{
    for (auto observer : _observers)
    {
        delete observer;
    }
    _observers.clear();
}

ObserversMgr *ObserversMgr::instance()
{
    static ObserversMgr observerMgr;

    return &observerMgr;
}

void ObserversMgr::firstBlockRead()
{
    for (auto observer : _observers)
    {
        observer->onFirstBlockRead();
    }
}

void ObserversMgr::beforeWriting()
{
    for (auto observer : _observers)
    {
        observer->beforeStartWriting();
    }
}

void ObserversMgr::oneBlockWrite(const std::string &block, bool isLast)
{
    for (auto observer : _observers)
    {
        observer->onWriteOneBlock(block, isLast);
    }
}

void ObserversMgr::endWriting()
{
    for (auto observer : _observers)
    {
        observer->onEndWriting();
    }
}


ConsoleObserver::ConsoleObserver()
                :IObserver()
{

}

ConsoleObserver::~ConsoleObserver()
{
}

void ConsoleObserver::onFirstBlockRead()
{

}

void ConsoleObserver::beforeStartWriting()
{
    cout << "bulk:";
}

void ConsoleObserver::onWriteOneBlock(const std::string &block, bool isLast)
{
    cout << " " << block;

    if (!isLast)
    {
        cout << ",";
    }
}

void ConsoleObserver::onEndWriting()
{
    cout << endl;
}


FileObserver::FileObserver()
{
}

FileObserver::~FileObserver()
{

}

void FileObserver::onFirstBlockRead()
{
    _firstBlockTime = sc::system_clock::now();
}

void FileObserver::beforeStartWriting()
{
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

    _file.open(logFile.relative_path().string());
    if (!_file.is_open())
    {
        cout << "Blocks file is not opened.";
    }
}

void FileObserver::onWriteOneBlock(const std::string &block, bool isLast)
{
    _file << block;
    if (!isLast)
    {
        _file << ",";
    }
}

void FileObserver::onEndWriting()
{
    _file.flush();
    _file.close();
}
