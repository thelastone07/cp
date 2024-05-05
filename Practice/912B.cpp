#include<bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    // ll count = 0;
    // ll ans = n;
    // ll bits = log2(n) +1;
    // cout << bits;
    if (k == 1) {
        cout << n;
        return;
    }
    // ll ans = ((ll)pow(2,bits)-1);
    // cout << unset ;
    ll ans = 1;
    while (ans <= n) ans *= 2;

    cout << ans - 1<< '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}