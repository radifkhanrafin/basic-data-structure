#include <bits/stdc++.h>
using namespace std;

void sort_my_list(list<int> &myList)
{
    myList.sort();
}

void remove_duplicates_from_list(list<int> &myList)
{
    myList.unique();
}

int main()
{

    list<int> myList;
    int value;

    while (true)
    {
        cin >> value;
        if (value == -1)
            break;

        myList.push_back(value);
    }

    sort_my_list(myList);
    remove_duplicates_from_list(myList);

    for (int val : myList)
    {
        cout << val << " ";
    }

    return 0;
}
