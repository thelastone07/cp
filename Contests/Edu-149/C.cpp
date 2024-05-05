#include<bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    string ans = "";
    int n = s.size();
    char last = s[0] == '?' ? '0' : s[0];
    ans += last;
    for (int i = 1; i < n; i++) {
        if (s[i] == '?') {
            ans += last;
        }
        else {
            ans += s[i];
            last = s[i];
        }
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