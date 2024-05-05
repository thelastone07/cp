#include<bits/stdc++.h>

using namespace std;

void solve() {
    int x, k;

    cin >> x >> k;

    vector<int> steps;
    int pos = x;

    while( pos != 0) {
        if (pos % k != 0){ 
            steps.push_back(pos);
            pos -= pos;
        } else {
            int val = pos;
            for( ; val % k == 0; val--);
            steps.push_back(val);
            pos -= val;
        }
    }
    cout << steps.size() << "\n";
    for ( auto a : steps) cout << a << " ";
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