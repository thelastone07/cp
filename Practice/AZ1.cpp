#include<bits/stdc++.h>

using namespace std;
#define int long long int

vector<int> subsetsum(vector<int>& a, int m){
    vector<int> ans;
    int n = a.size();
    for (int i = 0; i < (1LL << n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++){
            if ( i & (1LL << j)) sum = (sum + a[j])%m;
        }
        ans.push_back(sum);
    }

    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b, c, b1, c1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i < n/2) b.push_back(a[i]);
        else c.push_back(a[i]);
    }

    b1 = subsetsum(b,m);
    c1 = subsetsum(c,m);

    int cnt = 0;
    for (auto &it1: b1) {
        for (auto &it2 :c1) cnt = max(cnt, (it1+it2)%m);
    }

    cout << cnt << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}