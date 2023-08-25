#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <list>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;
namespace sc = std::chrono;
using namespace std;

class IObserver
{
public:
    IObserver() = default;
    virtual ~IObserver() = default;

    virtual void onFirstBlockRead() = 0;
    virtual void beforeStartWriting() = 0;
    virtual void onWriteOneBlock(const std::string &block, bool isLast) = 0;
    virtual void onEndWriting() = 0;
};

class ObserversMgr final
{
public:
    ~ObserversMgr();
    static ObserversMgr *instance();

    void firstBlockRead();
    void beforeWriting();
    void oneBlockWrite(const std::string &block, bool isLast);
    void endWriting();

private:
    ObserversMgr();

    std::list<IObserver *> _observers;
};

class ConsoleObserver : public IObserver
{
public:
    ConsoleObserver();
    ~ConsoleObserver();

    void onFirstBlockRead() override;
    void beforeStartWriting() override;
    void onWriteOneBlock(const std::string &block, bool isLast) override;
    void onEndWriting() override;
};

class FileObserver : public IObserver
{
public:
    FileObserver();
    ~FileObserver();

    void onFirstBlockRead() override;
    void beforeStartWriting() override;
    void onWriteOneBlock(const std::string &block, bool isLast) override;
    void onEndWriting() override;

private:
    sc::system_clock::time_point _firstBlockTime;
    ofstream _file;
};

#endif // IOBSERVER_H
