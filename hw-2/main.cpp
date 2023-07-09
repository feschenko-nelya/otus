#include "utils/IpAddresses.h"
  
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "File is not entered. Enter the name of the file with IP-addresses as a first parameter of command line." << endl;
        return 1;
    }

    IpAddresses ipList;

    if (!ipList.readFromFile(argv[1]))
    {
        return 1;
    }

    ipList.sortByDesc().toCout();
    ipList.filterByFirstByteIs1().toCout();
    ipList.filterByFirstByteIs46SecondIs70().toCout();
    ipList.filterByAnyByteIs46().toCout();

    return 0;
}
