#include<bits/stdc++.h>

using ll = long long;
using namespace std;


void solve() {
    int n;
    cin >> n;

    vector<ll> a(n,0);
    for (int i = 0; i < n ; i++) {
        cin >> a[i];
    }

     if ( n == 1) {
        cout << 1 << "\n" ;
        return;
    }

    auto ip = unique(a.begin(), a.end());
    a.resize(distance(a.begin(),ip));
    
    n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || i == n - 1 || (a[i] > a[i - 1]) == (a[i] > a[i + 1]))
        ans += 1;
    }
    cout << ans << "\n" ;
}

signed main() {
    ios :: sync_with_stdio (false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--){
        solve();
    }
}