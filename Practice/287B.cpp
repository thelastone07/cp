#include<bits/stdc++.h>

using namespace std;

using ll = long long;

ll n, k;

bool check(int l) {
    ll f = k - l + 1;
    // cout << "n" << l << " " << "f" << f;
    ll temp = l * ( 2*f + l - 1) / 2 - l + 1;
    // cout << " temp" << temp << '\n';
    return (temp >= n);
}

void solve() {
    cin >> n >> k;
    
    int lo = 1, hi = k - 1, ans = -1;

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    while (hi >= lo) {
        int mid = (hi + lo) / 2;

        if (check(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }

    cout << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}