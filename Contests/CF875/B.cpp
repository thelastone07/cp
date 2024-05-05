#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> fa(2*n + 1), fb(2*n + 1);
    int p = 0;
    for (int i = 1; i < n; i++) {
        if( a[i]!= a[i-1]) {
            fa[a[i-1]] = max( fa[a[i-1]], i-p);
            p = i;
        }
    }
    fa[a[n-1]] = max(fa[a[n-1]], n-p); 

    p = 0;
    for (int i = 1; i < n; i++) {
        if( b[i]!= b[i-1]) {
            fb[b[i-1]] = max( fb[b[i-1]], i-p);
            p = i;
        }
    }
    fb[b[n-1]] = max(fb[b[n-1]], n-p);

    int ans = 0;
    for (int i = 1; i <= 2*n; i++) {
        ans = max(ans, fa[i] + fb[i]);
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
}