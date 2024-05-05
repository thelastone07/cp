#include<bits/stdc++.h>

using ll = long long;
using namespace std;

void solve() {
    ll n, k;
    cin >> n >> k;

    ll a[n];
    for( ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    ll max_sum = -1e18;
    vector<ll> prefix_sum(n+1,0);
    for(int i = 0; i < n; i++){
        prefix_sum[i+1] = prefix_sum[i] + a[i];
    }
    for ( ll kl = 0; kl <= k ; kl++) {
        max_sum = max(max_sum, prefix_sum[n-(k-kl)]-prefix_sum[2*kl]);
    }

    cout << max_sum <<"\n";
    
}

signed main () {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;

    while ( t-- ){
        solve();
    }
}