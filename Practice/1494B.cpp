#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, U, R, L, D;
    cin >> n >> U >> R >> D >> L;

    for (int mask = 0; mask < 16; mask++) {
        bool ok = true;
        int u = 0, d = 0, l = 0, r = 0;
        if (mask&1) {
            u++;
            l++;
        }
        if (mask&2) {
            l++;
            d++;
        }
        if (mask&4) {
            d++;
            r++;
        }
        if (mask&8) {
            r++;
            u++;
        }

        if ( u > U || u + (n - 2) < U) ok = false;
        if ( l > L || l + (n - 2) < L) ok = false;
        if ( r > R || r + (n - 2) < R) ok = false;
        if ( d > D || d + (n - 2) < D) ok = false;

        if (ok) {
            cout << "YES\n";
            return ;
        }
    } 
    cout << "NO\n";
    
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}