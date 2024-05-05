#include <bits/stdc++.h>
#include <stdio.h>
#define ll long long
using namespace std;

int sequence_master(ll arr[], int n)
{
    ll ans = 0, sum = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        ans += abs(arr[i]);
        sum += abs(arr[i] + 1);
    }
    if (n == 1)
    {
        ans = min(ans, abs(arr[0] - arr[1]));
    }
    if (n == 2)
    {
        ans = min(ans, abs(arr[0] - 2) + abs(arr[1] - 2) + abs(arr[2] - 2) + abs(arr[3] - 2));
    }
    if (n % 2 == 0)
    {
        for (int i = 0; i < 2 * n; i++)
            ans = min(ans, sum - abs(arr[i] + 1) + abs(arr[i] - n));
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    int ans[t];
    while (t)
    {
        int n;
        cin >> n;
        ll arr[2 * n];
        for (int i = 0; i < 2 * n; i++)
            cin >> arr[i];
        // cout<<"entering sequence master";
        ans[t - 1] = sequence_master(arr, n);
        // cout<<"exiting sequence master";
        t--;
        // cout<<t;
    }
    // cout<<"out of test";
    for (int i = sizeof(ans) / sizeof(int) - 1; i >= 0; i--)
        cout << ans[i] << "\n";
    return 0;
}
