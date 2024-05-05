#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, m;
vector<ll> a;

bool check(ll x) {
    ll mx = -1;
    for (ll i = 0; i < n; i++) {
        if ( a[i]  < mx && (a[i] + x) < m ) return false;
        else {
            if ((a[i] + x) >= m && ((a[i] + x)%m) >= mx) continue;
            else mx = a[i];
        }
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    a.assign(n+1,0);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll lo = 0, hi = 1e9, ans = 0;

    while (hi >= lo) {
        ll mid = (hi + lo) / 2;
        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }

    cout << ans << '\n';

    return 0;
}

