#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int n_negs = 0;
    int n_odds = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if( a[i] % 2) n_odds += 1;
    }
    int min_ = *min_element(a, a+n);
    
    int r = min_ % 2;
    if( r == 0 && n_odds > 0){
        cout << "NO\n";
        return;
    }
    else {
        cout << "YES\n";
        return;
    }

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