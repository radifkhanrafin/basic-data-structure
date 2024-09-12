#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
        int currentIndex = v.size() - 1;
        // cout << currentIndex;

        while (current_exception != 0)
        {
            int parentIndex = (currentIndex - 1) / 2;
            if (v[parentIndex] < v[currentIndex])
            {
                swap(v[parentIndex], v[currentIndex]);
            }
            else
                break;
            currentIndex = parentIndex;
        }
    }

    for (int val : v)
    {
        cout << val << " ";
    }

    return 0;
}