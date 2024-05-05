#include<bits/stdc++.h>

using namespace std;

using ll = long long;

bool check (ll a, ll b, ll c) {
    if ( a > c or b > c ) return false;
    if ( a == c or b == c) return true;
    if ( log10( pow(10,a)-1 + pow(10,b)-1) >= c) return true;
    return false;
}
bool check( ll a, ll b, ll c, ll k) {
    if ( (fact(a)) * fact(b) > )
}
void solve () {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;

    if (!check (a,b,c)) {
        cout << -1 << "\n";
        return;
    }
    if (!ccheck(a,b,c,k)) {
        cout << -1 << "\n";
        return;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}