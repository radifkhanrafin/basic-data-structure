#include <bits/stdc++.h>
using namespace std;

int main()
{
    string sentence;
    getline(cin, sentence);
    string word;
    stringstream ss(sentence);
    map<string, int> ms;

    while (ss >> word)
    {
        ms[word]++;
        // cout << word << endl;
    }
    for (auto it = ms.begin(); it != ms.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}