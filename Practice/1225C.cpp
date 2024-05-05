#include<bits/stdc++.h>

using namespace std;



void solve() {
    int n, p;
    cin >> n >> p;
    bool ok = false;
    int ans = -1;
    for (int k = 1; k < 30 ;k++) {
        int val = n - p*k;
        // cout << "val" << val << " k " << k << "\n";
        int cnt = 0;
        // vector<int> v(31,0);
        for (int i = 0; i < 30; i++) {
            if ( val & ( 1 << i)) {
                cnt++;
                // if (i > 0)  v[i++];
            }
        }
        ok |=  ( cnt <= k && k <= val);
        if(ok) {
            ans = k;
            break;
        }
    }
    cout << ans << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;


}