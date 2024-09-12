#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        queue<char> q;

        for (char c : s)
        {
            if (c == '0')
            {
                if (!q.empty() && q.back() == '1')
                {
                    q.pop();
                }
                else
                {
                    q.push(c);
                }
            }
            else if (c == '1')
            {
                if (!q.empty() && q.back() == '0')
                {
                    q.pop();
                }
                else
                {
                    q.push(c);
                }
            }
        }

        cout << (q.empty() ? "YES" : "NO") << endl;
    }

    return 0;
}
