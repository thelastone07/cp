#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> dp(n+1, vector<int>(1 << 6,0));

    for (int i = 1; i <= n; i++) {
        for (int mask = 0; mask < (1 << 6); mask++) {
            dp[i][mask] = dp[i-1][mask] ;
            dp[i][mask] %= mod ;
            dp[i][mask & a[i]] += dp[i-1][mask] ;
            dp[i][mask & a[i]] %= mod ;
        }
        dp[i][a[i]] = dp[i][a[i]] + 1;
        dp[i][a[i]] %= mod;
    }

    int ans = 0;

    for (int mask = 0; mask < (1 << 6); mask++) {
        if (__builtin_popcount(mask) == k) {
            ans += dp[n][mask];
            ans %= mod;
        }
    }
    cout << ans << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}