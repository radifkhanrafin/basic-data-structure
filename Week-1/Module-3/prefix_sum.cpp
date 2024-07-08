#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n, q;
  cin >> n >> q;
  long long arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  long long preSum[n];
  preSum[0] = arr[0];

  for (int i = 1; i < n; i++)
  {
    preSum[i] = arr[i] + preSum[i - 1];
  }


  while (q--)
  {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    long long sum;
    if (a == 0)
      sum = preSum[b];
    else
      sum = preSum[b] - preSum[a - 1];

    cout << sum << endl;
  }

  return 0;
}
