#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int,vector<int>,greater<int>> pq;

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            int x;
            cin >> x;
            pq.push(x); // o(logN)
        }
        else if (n == 1)
        {
            pq.pop(); // o(logN)
        }
        else if (n == 2)
        {
            cout << pq.top()<<" "<<endl; // o(1)
        }
        else
            break;
    }

    return 0;
}