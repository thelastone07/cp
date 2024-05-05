#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    ll p = 1;
    for (int i = 0; i < 31; i++) {
        if(k & (1<<i)){
                ans = (ans + p) % MOD;
            }
            p *= n;
            p %= MOD;
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}