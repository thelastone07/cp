// #include<bits/stdc++.h>

// using namespace std;

// using ll = long long;

// ll n, health;
// vector<int> a;

// bool check(ll k) {
//     // cout << "K " << k;
//     ll damage = 0;
//     for (int i = 0; i < n - 1; i++) {
//         if (a[i+1] - a[i] < k) {
//             damage += a[i+1] - a[i];
//         }
//         else damage += k;

//     }
//     damage += k;
//     // cout << " damage " << damage << " health " << health << '\n';

//     // cout << bool(k >= h);
//     return (k >= health);
// }

// void solve() {
//     a.clear();
    
//     cin >> n >> health;
    
//     a.resize(n);
//     for (int i = 0; i < n; i++) cin >> a[i];

//     if (n == 1) {
//         cout << health;
//         return;
//     }
//     ll lo = 1, hi = health, ans = 0;

//     while (hi >= lo) {
//         ll mid = (lo + hi) / 2;
//         // cout << " mid " << mid << '\n';
//         if (check(mid)) {
//             ans = mid;
//             hi = mid - 1;
//         // cout << " hi " << hi << '\n';

//         }
//         else lo = mid + 1;
//         // cout << " lo " << mid << '\n';

//     }

//     cout << ans << '\n';
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);
    
//     int t;
//     cin >> t;

//     while (t--) solve();

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

using li = long long;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    li h;
    cin >> n >> h;
    vector<li> a(n);
    for (li &x : a) cin >> x;
    li l = 1, r = 1e18;
    while (l <= r) {
      li m = (l + r) / 2;
      li sum = m;
      for (int i = 0; i < n - 1; ++i) 
        sum += min(m, a[i + 1] - a[i]);
      if (sum < h) l = m + 1;
      else r = m - 1;
    }
    cout << r + 1 << '\n';
  }
}