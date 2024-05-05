#include<bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n,0);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int t = 0; t < (1 << n); t++) {
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (t & (1 << i)) x += a[i];
            else x -= a[i];
        }
        if (x % 360 == 0) {
            cout << "YES\n";
            return;
        }
     }
     cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}