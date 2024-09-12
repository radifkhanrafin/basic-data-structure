#include <bits/stdc++.h>
using namespace std;

class myQueue
{
public:
    list<int> myQueue_list;

    void push(int val)
    {
        myQueue_list.push_back(val);
    };

    void pop()
    {
        myQueue_list.pop_front();
    }

    int font()
    {

        return myQueue_list.front();
    }
    int size()
    {
        return size();
    }
    bool empty()
    {
        return myQueue_list.empty();
    }
};
int main()
{
    myQueue q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    while (!q.empty())
    {
        cout << q.font() << endl;
        q.pop();
    }

    return 0;
}