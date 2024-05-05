#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    set<int> numbers;
    numbers.insert(0);
    int last = 0;
    for (int i = 0; i < n; i++) {
        if( s[i] == '>') {
            //find a number smaller than last
            if ( numbers.find(last-1) != numbers.end()) {
                last = *numbers.find(last-1);
            }
            else {
                numbers.insert(last - 1);
                last = last - 1;
            }
        }
        else {
            //find a number greater than last
            if ( numbers.find(last+1) != numbers.end()) {
                last = *numbers.find(last+1);
            }
            else {
                numbers.insert(last + 1);
                last += 1;
            }
        }
    }
    cout << numbers.size() << "\n";
}

signed main() {
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}