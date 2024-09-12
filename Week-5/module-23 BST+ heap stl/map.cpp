#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> ms;
    ms.insert({"Mahfuz Hossain", 4005});
    ms.insert({"shamim Hossain", 4105});
    ms.insert({"miraj Hossain", 4001});
    ms.insert({"mydul Hossain", 4002});

    for (auto it = ms.begin(); it != ms.end(); it++)
    {
        cout << it->first << " " << it->second<<endl;
    }

    return 0;
}