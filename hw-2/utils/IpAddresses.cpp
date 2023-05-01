#include "IpAddresses.h"
#include <iostream>
#include <fstream>
#include <algorithm>

bool IpAddresses::readFromFile(const string &fileName)
{
    wifstream file(fileName.data());
    if (!file.is_open())
    {
        cout << "File is not opened: " << fileName.data() << "." << endl;
        return false;
    }

    wstring line;
    while (getline(file, line))
    {
        IpAddress ip;

        if (!ip.read(line))
        {
            wcout << "Error of reading IP: '" << line << "'." << endl;
        }

        if (!ip.isEmpty())
        {
            push_back(ip);
        }
    }
    file.close();

    return true;
}

IpAddresses IpAddresses::sortByDesc() const
{
    IpAddresses sortAddresses;
    sortAddresses.assign(begin(), end());

    sort(sortAddresses.begin(), sortAddresses.end(),
         [](const IpAddress &left, const IpAddress &right) -> bool
         {
            return !left.isLess(right);
         });

    return sortAddresses;
}

IpAddresses IpAddresses::filterByFirstByteIs1() const
{
    IpAddresses resAddresses;

    copy_if(cbegin(), cend(), inserter(resAddresses, resAddresses.end()),
            [](const IpAddress &address) -> bool
            {
                return (address.getNumbers()[0] == 1);
            });

    return resAddresses;
}

IpAddresses IpAddresses::filterByFirstByteIs46SecondIs70() const
{
    IpAddresses resAddresses;

    copy_if(cbegin(), cend(), inserter(resAddresses, resAddresses.end()),
            [](const IpAddress &address) -> bool
            {
                return !address.getNumbers().empty()
                       && (address.getNumbers()[0] == 46)
                       && ((address.getNumbers().size() > 0) && (address.getNumbers()[1] == 70));
            });

    return resAddresses;
}

IpAddresses IpAddresses::filterByAnyByteIs46() const
{
    IpAddresses resAddresses;

    copy_if(cbegin(), cend(), inserter(resAddresses, resAddresses.end()),
            [](const IpAddress &address) -> bool
            {
                return address.contains(46);
            });

    return resAddresses;
}

void IpAddresses::toCout(const wstring &caption) const
{
    if (!caption.empty())
    {
        wcout << endl << caption << endl;
    }

    for (auto it = cbegin(); it != cend(); ++it)
    {
        wcout << it->getAddress() << endl;
    }
}
