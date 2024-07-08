#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, q;
  cin >> n >> q;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  for (int i = 0; i < n; i++)
  {
    // cout<< arr[i]<<" ";
  }
cout<<endl;
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    long long int sum = 0;
    l--;
    r--;
    // cout << l << " " << r << endl;
    for (int i = l; i <= r; i++)
    {
      // cout << arr[i]<<" ";
     
      sum += arr[i];
    }
    //  cout<<endl;
    cout << sum << endl;
  }

  cout << "";
  return 0;
}