#include <iostream>
#include <list>
using namespace std;

void print_list(list<int> &myList)
{
    cout << "L -> ";
    for (auto it = myList.begin(); it != myList.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "R -> ";
    for (auto it = myList.rbegin(); it != myList.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    list<int> myList;

    for (int i = 0; i < n; ++i)
    {
        int x, v;
        cin >> x >> v;

        if (x == 0)
        {
            myList.push_front(v);
        }
        else if (x == 1)
        {
            myList.push_back(v);
        }
        else if (x == 2)
        {

            if (v >= 0 && v < myList.size())
            {
                auto it = myList.begin();
                advance(it, v);
                myList.erase(it);
            }
        }

        print_list(myList);
    }

    return 0;
}
