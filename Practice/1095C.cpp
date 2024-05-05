#include<bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;
    bool ok = false;
    queue<ll> q;
    map<int, int> ans;

    for (int i = 0; i < log2(n)+1; i++) {
        if (n & (1 << i)){
             if ( i != 0) q.push(pow(2,i));
             ans[1 << i]++;
        }
    }
    
    if (ans.size() > k) {
        cout << "NO\n";
        return;
    }
    ll count = ans.size();
    while ( count < k && !q.empty()) {
        int z = q.front();
        q.pop();
        ans[z]--;
        ans[z/2] += 2;
        if (z / 2 > 1) {
            q.push( z / 2);
            q.push( z / 2);
        }
        count++;
    }  
    if (count < k) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (auto &x : ans) for (int i = 0; i < x.second; i++)
        cout << x.first << " ";
    cout << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}