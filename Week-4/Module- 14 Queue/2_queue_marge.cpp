#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> queue_1, queue_2, marge_queue;
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        queue_1.push(x);
    }
    // while (!queue_1.empty())
    // {
    //     cout << queue_1.front() << " ";
    //     queue_1.pop();
    // }
    // cout << endl;

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        queue_2.push(x);
    }
    // while (!queue_2.empty())
    // {
    //     cout << queue_2.front() << " ";
    //     queue_2.pop();
    // }
    // cout << endl;
    // cout << n << " " << m;
    while (!queue_1.empty())
    {
        marge_queue.push(queue_1.front());
        queue_1.pop();
    }

    while (!queue_2.empty())
    {
        marge_queue.push(queue_2.front());
        queue_2.pop();
    }

    while (!marge_queue.empty())
    {
        cout << marge_queue.front() << " ";
        marge_queue.pop();
    }

    return 0;
}