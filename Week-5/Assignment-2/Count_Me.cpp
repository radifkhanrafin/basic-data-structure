#include <iostream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

void processSentence(string &S)
{
    map<string, int> wordCount;
    stringstream ss(S);
    string word;

    string maxWord = "";
    int maxCount = 0;

    while (ss >> word)
    {
        wordCount[word]++;

        if (wordCount[word] > maxCount)
        {
            maxWord = word;
            maxCount = wordCount[word];
        }
    }

    cout << maxWord << " " << maxCount << endl;
}

int main()
{
    int T;
    cin >> T;
    cin.ignore();

    while (T--)
    {
        string S;
        getline(cin, S);

        processSentence(S);
    }

    return 0;
}
