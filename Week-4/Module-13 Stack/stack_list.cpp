#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> list;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        list.push(x);
    }

    while (!list.empty())
    {
        cout << "value " << list.top() << endl;
        cout << "size " << list.size() << endl;
        list.pop();
    }

    return 0;
}