#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    map<string, vector<int>> m;

    for (int i = 0; i < n; ++i)
    {
        string s;
        int num;
        cin >> s >> num;
        m[s].push_back(num);
    }

    vector<pair<string, int>> result;

    for (auto &kv : m)
    {
        vector<int> &nums = kv.second;
        sort(nums.begin(), nums.end(), greater<int>());

        for (int num : nums)
        {
            result.push_back({kv.first, num});
        }
    }

    for (int i = 0; i < result.size(); ++i)
    {
        cout << result[i].first << " " << result[i].second << endl;
    }

    return 0;
}
