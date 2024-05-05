#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int s = n+1;
    vector<int> b(n);
    for ( int i = 0; i < n; i++) {
        b[i] = s - a[i];
        cout << b[i] << " \n"[ i == n-1];
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