#include<bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n,0);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<ll> bits(32,0);

    for (int i = 0; i < 32; i++) 
        for (int j = 0; j < n; j++) 
            if (a[j] & (1ll << i)) bits[i]++;
    
    // for (auto &x: bits) cout << x << " ";
    for (int i = 1; i <= n; i++) {
        bool ok = true;
        for (int j = 0; j < 31; j++) {
            if ((bits[j] % i) != 0)
                ok = false;
        }
        if (ok) cout << i << " ";
    }
    cout << "\n";
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}