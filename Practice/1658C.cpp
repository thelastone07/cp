#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int min = 0, min_num = 0;;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        if (c[i] == 1) {
            min = i;
            min_num++;
        }
    }

    if (min_num != 1) {
        cout << "no\n";
        return;
    }

    bool possible = true;

    vector<int> a;

    for (int i = min; i < n; i++) {
        a.push_back(c[i]);
    }
    for (int i = 0; i < min; i++) {
        a.push_back(c[i]);
    }

    for (int i = 1; i < n; i++) {
        if (a[i] - a[i-1] >= 2)
            possible = false;
    }

    if (!possible) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" <<'\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}