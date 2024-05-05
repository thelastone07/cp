#include<bits/stdc++.h>

using namespace std;
int n, k;
vector<int> needed,has;

bool check(int mid) {
    int cost = 0;
    for (int i = 0; i < n; i++) {
        if ( (mid*needed[i] - has[i]) >= 0)
            cost += (mid*needed[i] - has[i]);
    }
    if (k >= cost) return true;
    return false;
}

void solve(){
    cin >> n >> k;

    needed.assign(n,0); 
    has.assign(n,0);

    for (int i = 0; i < n; i++) cin >> needed[i];
    for (int i = 0; i < n; i++) cin >> has[i];

    int lo = 0, hi = 1e4, ans = 0;

    while (hi >= lo) {
        int mid = (hi + lo) / 2;
        if (check(mid)){
            ans = mid;
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    cout << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    solve();
}