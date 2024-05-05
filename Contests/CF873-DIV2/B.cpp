#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

void solve() {
    int n;
    cin >> n;

    int a[n];
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos.push_back(abs(a[i] - i - 1));
    }
    
    int ans = pos[0];
    for (int i = 1; i < n; i++) {
        ans = gcd(pos[i], ans);
    }
    cout << ans << "\n";
}

signed main() {
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}