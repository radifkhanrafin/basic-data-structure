#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v1;

    vector<int> v2(5);

    vector<int> v3(5, 10);

    vector<int> v4(v3);

    int arr[6] = {10, 20, 30, 40, 50, 60};

    vector<int> v5(arr, arr + 6);

    for (int i = 0; i < v2.size(); i++)
    {
        cout << "V2-" << v2[i] << endl;
    }

    for (int i = 0; i < v3.size(); i++)
    {
        cout << "V3-" << v3[i] << endl;
    }
    for (int i = 0; i < v4.size(); i++)
    {
        cout << "V4-" << v4[i] << endl;
    }

    for (int i = 0; i < v5.size(); i++)
    {
        cout << "V5-" << v5[i] << endl;
    }

    cout << "size of vector - " << v1.size();
    return 0;
}