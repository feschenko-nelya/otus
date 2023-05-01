#ifndef IPADDRESS_H
#define IPADDRESS_H

#include <iostream>
#include <vector>
using namespace std;

class IpAddress
{
public:
    IpAddress() = default;

    wstring getAddress() const;
    bool read(const wstring &line);
    const vector<int> &getNumbers() const;
    bool contains(const int &number) const;
    bool isEmpty() const;
    bool isLess(const IpAddress &address) const;

private:
    wstring _address;
    vector<int> _numbers;

    bool parseNumbers();
};

#endif // IPADDRESS_H
