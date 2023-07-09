#include <iostream>
#include <queue>
#include <algorithm>
#include "BlocksReaderMgr.h"

using namespace std;

inline void toLower(string &str)
{
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c)
                   {
                        return std::tolower(c);
                   } );
}

inline bool isEqual(string src, string dst)
{
    toLower(src);
    toLower(dst);

    return src.compare(dst) == 0;
}


int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "N - number of blocks - parameter is absent. Add value of blocks in command line, for example: bulk 5";
        return 1;
    }

    int N = std::stoi(argv[1]);
    if (N <= 0)
    {
        cout << "Value of N must be more than 0, for example: 1, 20 etc.";
        return 1;
    }

    cout << "Start blocks entering... (for stop print 'EOF')" << endl;

    BlocksReaderMgr blocksReader(N);

    bool isEof = false;
    while (!isEof)
    {
        string str;
        cout << "> ";
        cin >> str;

        isEof = isEqual(str, "eof");

        if (!isEof)
        {
            blocksReader.read(str);
        }
        else
        {
            blocksReader.flush();
        }
    }

    return 0;
}
