#include <bits/stdc++.h>
using namespace std;

class myStack
{

public:
    vector<int> list;
    void push(int val)
    {
        list.push_back(val);
    }
    void pop()
    {
        list.pop_back();
    }
    int top()
    {
        return list.back();
    }
    int size()
    {
        return list.size();
    }
    bool empty()
    {
        if (list.size() == 0)
        {
            return true;
        }
        else
            return false;
    }
};

int main()
{
    myStack st;
    // st.push(10);
    // st.push(20);
    // cout << st.top() << endl;

    // st.pop();
    // cout << st.top() << endl;
    // cout << st.size() << endl;
    // st.push(10);
    // if (!st.empty())
    // {
    //     cout << "from if " << st.top() << endl;
    // }
    // input from loop

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << i << endl;
        int x;
        cin >> x;
        st.push(x);
    }

    cout << "Output from loop : " << endl;
    while (st.empty() == false)
    {
        cout << st.top() << endl;
        st.pop();
    }

    return 0;
}