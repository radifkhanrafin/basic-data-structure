#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<string> ticket;

    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;

        if (command == "0")
        {
            string name;
            cin >> name;
            ticket.push(name);
        }
        else if (command == "1")
        {
            if (!ticket.empty())
            {
                cout << ticket.front() << endl;
                ticket.pop();
            }
            else
            {
                cout << "Invalid" << endl;
            }
        }
    }

    return 0;
}
