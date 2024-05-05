#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans= "";
    bool flag = true;
    char last = s[0];
    ans += last;
    for (int i = 1; i < n; i++) {
        if(flag) {
            if (s[i] == last) {
                flag = false;
            }
            continue;
        }
        else {
            ans += s[i];
            last = s[i];
            flag = true;
        }
    }

    cout << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}