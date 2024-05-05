#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> cnt(101,0);
    vector<int> l(n);
    int max_ele = 0;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
        cnt[l[i]]++;
        max_ele = max(max_ele, l[i]);
    }
    
    int temp = cnt[0];
    if (temp == 0) {
        cout << "NO\n";
        return;
    }
    int i = 1;
    
    // cout << max_ele << " ";
    while ( i <= max_ele) {
        int curr = cnt[i];

        if (curr > temp) {
            cout << "NO\n";
            return;
        }
        temp = curr;
        
        i++ ;
    }
    
    cout << "YES\n";
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}