#ifndef IPADDRESSES_H
#define IPADDRESSES_H

#include "IpAddress.h"

class IpAddresses : public std::vector<IpAddress>
{
public:
    IpAddresses() = default;

    bool readFromFile(const string &fileName);
    IpAddresses sortByDesc() const;
    IpAddresses filterByFirstByteIs1() const;
    IpAddresses filterByFirstByteIs46SecondIs70() const;
    IpAddresses filterByAnyByteIs46() const;

    void toCout(const wstring &caption = L"") const;
};

#endif // IPADDRESSES_H
