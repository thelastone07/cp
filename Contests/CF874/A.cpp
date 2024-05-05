#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<string> tunes;
    for(int i = 0; i < n-1; i++) {
        tunes.insert(s.substr(i,2));
    }
    cout << tunes.size();
    cout << "\n";
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