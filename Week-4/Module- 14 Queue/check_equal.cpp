#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> stack_1, stack_2;
    int m, n, val, flag = 0;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> val;
        stack_1.push(val);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        stack_2.push(val);
    }

    if (stack_1.size() == stack_2.size())
    {
        flag = 1;
        while (!stack_1.empty())
        {
            if (stack_1.top() == stack_2.top())
            {
                flag = 1;
            }
            else
            {
                flag = 0;
            }
            stack_1.pop();
            stack_2.pop();
        }
    }
    else
        flag = 0;

    if (flag == 1)
    {
        cout << "YES";
    }
    else
        cout << "NO";

    return 0;
}