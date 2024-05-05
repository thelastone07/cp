#include<bits/stdc++.h>

using namespace std;

using ll = long long;
int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n+1);
    vector<int> numbers(1e9+1,0);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        numbers[a[i]]++;
    }
    sort(a.begin(), a.end());
    a.erase( unique(a.begin(), a.end()), a.end());

    int i = 0;
    int j = m;
    ll ans = 0;

    while( j < a.size()) {
        if( a[j] - a[i] < m) {
            int product = 1;
            for( int x = i; x <= j; x++) {
                product *= numbers[a[x]];
                ans += product % mod;
            }
        }
        ++i;
        ++j;
    }
    cout << ans % mod << "\n";
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
    
    return 0;
}