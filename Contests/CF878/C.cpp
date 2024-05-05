#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

void solve() {
    ll n, k, q;

    cin >> n >> k >> q;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    ll ans = 0, len = 0;

    for (ll i = 0; i < n; i++) {
        if (a[i] <= q) len++;
        else {
            if (len >= k)
                ans += (len - k + 1) * (len - k +2) / 2;
            len = 0;
        }
    }

    if (len >= k) ans += (len - k + 1) * (len - k + 2) / 2;

    cout << ans <<"\n";


}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}