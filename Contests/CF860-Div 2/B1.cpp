#include<bits/stdc++.h>

using i64 = long long;
using namespace std;


void three7s() {
    int m;
    cin >> m;

    vector<vector<int>> a(m);

    for (int i = 0; i < m; i++) {
        int n;
        cin >> n;

        a[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    //if you can't find an answer at a level -1.
    set<int> nowin;
    vector<int> ans(m);
    for ( int i = m - 1; i >= 0; i--) {
        int x = -1;
        for ( auto y : a[i]) {
            if ( !nowin.count(y)) {
                x = y;
                nowin.insert(y);
            }
        }
        if ( x == -1) {
            cout << -1 << "\n";
            return;
        }
        ans[i] = x;
    }
    for( int i = 0; i < m; i++) {
        cout << ans[i] << " \n"[i == m - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--) {
        three7s();
    }

    return 0;
}