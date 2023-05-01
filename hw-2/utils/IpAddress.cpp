#include "IpAddress.h"
#include <algorithm>

wstring IpAddress::getAddress() const
{
    return _address;
}

bool IpAddress::isEmpty() const
{
    return _address.empty();
}

bool IpAddress::read(const wstring &line)
{
    _address.clear();

    bool isAllCorrect = true;
    bool isTab = false;
    int i = 0;
    while (i < line.length() && isAllCorrect && !isTab)
    {
        isTab = isspace(line.at(i));
        if (!isTab)
        {
            isAllCorrect = isdigit(line.at(i)) || (line.at(i) == '.');
            ++i;
        }
    }

    if (!isAllCorrect || (line.back() == L'.'))
    {
        return false;
    }

    _address = line.substr(0, i);

    return parseNumbers();
}

const vector<int> &IpAddress::getNumbers() const
{
    return _numbers;
}

bool IpAddress::contains(const int &number) const
{
    auto it = find_if(getNumbers().cbegin(), getNumbers().cend(),
                      [=](const int &val) -> bool
                      {
                          return (val == number);
                      });

    return (it != getNumbers().cend());
}

bool IpAddress::isLess(const IpAddress &address) const
{
    auto numbersForCompare = address.getNumbers();

    if (_numbers.size() < numbersForCompare.size())
    {
        return false;
    }

    for (int i = 0; i < _numbers.size(); i++)
    {
        if (_numbers.at(i) < numbersForCompare.at(i))
        {
            return true;
        }

        if (_numbers.at(i) > numbersForCompare.at(i))
        {
            return false;
        }
    }

    return false;
}

bool IpAddress::parseNumbers()
{
    _numbers.clear();

    size_t firstPos = 0;
    size_t lastPos = _address.find('.', firstPos);
    bool isEnd = false;
    while (!isEnd)
    {
        if (lastPos == wstring::npos)
        {
            lastPos = _address.size();
            isEnd = true;
        }

        wstring number = _address.substr(firstPos, lastPos - firstPos);
        try
        {
            _numbers.push_back(stoi(number));
        }
        catch (...)
        {
            wcout << "Error of converting: '" << number << "'. Address: '" << _address << "'." << endl;
            _numbers.clear();
            return false;
        }

        firstPos = lastPos + 1;
        lastPos = _address.find('.', firstPos);
    }

    return true;
}

