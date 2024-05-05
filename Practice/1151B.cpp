#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m,0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    vector<int> ans(n);
    int x = 0;
    for (int i = 0; i < n; i++) {
        int y = x^a[i][0];
        if (y > 0) {
            x = y;
            ans[i] = 1;
            continue;
        }
        else {
            int j = 1;
            while ( y == 0 && j < a[i].size()) {
                y = x;
                y = y^a[i][j];
                j++;
            }
            ans[i] = j ;
            x = y;
        }
    }


    if (x == 0) cout << "NIE\n";
    else {
        cout << "TAK\n";
        for (auto &var : ans) cout << var << " ";
        cout << "\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}