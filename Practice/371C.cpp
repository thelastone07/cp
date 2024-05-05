// #include<bits/stdc++.h>

// using namespace std;
// using ll = long long;

// void solve() {
//     string s;
//     cin >> s;

//     vector<int> n(3), p(3);
//     for (int i = 0; i < 3; i++) cin >> n[i];
//     for (int i = 0; i < 3; i++) cin >> p[i];

//     ll r;
//     cin >> r;

//     vector<int> req(3,0);
//     for (auto &ch: s) {
//         if (ch == 'B') req[0]++;
//         if (ch == 'S') req[1]++;
//         if (ch == 'C') req[2]++;
//     }

//     ll price = req[0]*p[0] + req[1]*p[1] + req[2]*p[2];

//     for (int i = 0; i < 2; i++) {
//         if (!req[i]) continue;
//         r += n[i]*p[i];
//     }

//     ll ans = r/price;

//     cout << ans << '\n';
// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);

//     solve();

//     return 0;
// }


#include<bits/stdc++.h>

using namespace std;

using ll = long long;

string s;
vector<ll> n,p,cnt;
ll r;

bool check(int mid){

    ll cost = 0;
    
    for (int i = 0; i < 2; i++) {
        if ( (mid*cnt[i] - n[i]) >= 0)
            cost += (mid*cnt[i] - n[i])* p[i];
    }

    if (cost <= r) return true;
    return false;

}

void solve() {
    cin >> s;

    n.resize(3,0);
    p.resize(3,0);
    cnt.resize(3,0);
    for (int i = 0; i < 2; i++) cin >> n[i];
    for (int i = 0; i < 2; i++) cin >> p[i];

    cin >> r;

    for (auto &ch : s) {
        if (ch == 'B') cnt[0]++;
        else if (ch == 'S') cnt[1]++;
        else cnt[2]++;
    }

    ll l = 0, h = 1e13, ans = 0;

    while (l <= h) {
        ll mid = (l + h) / 2;

        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else h = mid - 1;
    }

    cout << ans << '\n';


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}

