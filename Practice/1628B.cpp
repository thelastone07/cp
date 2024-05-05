#include<bits/stdc++.h>

using namespace std;



void solve() {
    int n;
    cin >> n;

    vector<string> s(n);
    vector<int> size(n);
    bool possible = false;

    for (int i = 0; i < n; i++) {
        cin >> s[i];

        size[i] = s[i].size();
        if (size[i] == 1) possible = true;
    }

    if (possible) {
        cout << "YES\n";
        return;
    }

    map<string,int> count;

    for (int i = n-1; i >= 0; i--) {
        string s1 = s[i], s2 = s[i];
        reverse(s2.begin(), s2.end());
        if (size[i] == 2) {
            if (s1 == s2) {
                possible = true;
                break;
            }
            if (count[s2]) {
                possible = true;
                break;
            }
            for (int j = 0; j < 26; j++) {
                string ss ;
                ss += ('a' + j);
                ss += s2;
                if (count[ss]){
                    possible = true;
                    break;
                }
            }
        }
        if (size[i] == 3) {
            if (s1 == s2) {
                possible = true;
                break;
            }
            if(count[s2]) {
                possible = true;
                break;
            }
            if (count[s2.substr(1,2)]) {
                possible = true;
                break;
            }
        }
        count[s1] = 1;
    }

    for (auto &a : count) {
        if (a.second > 1) possible = true;
    }

    if (!possible) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

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