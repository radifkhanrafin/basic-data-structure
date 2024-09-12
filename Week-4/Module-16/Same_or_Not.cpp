#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> list_1;
    queue<int> list_2;

    int m, n, val, flag = 0;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        cin >> val;
        list_1.push(val);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        list_2.push(val);
    }

    if (list_1.size() == list_2.size())
    {
        flag = 1;
        while (!list_1.empty())
        {
            if (list_1.top() == list_2.front())
            {
                flag = 1;
            }
            else
                flag = 0;
            list_1.pop();
            list_2.pop();
        }
    }
    else
        flag = 0;

    if (flag == 1)

        cout << "YES";
    else
        cout << "NO";

    return 0;
}