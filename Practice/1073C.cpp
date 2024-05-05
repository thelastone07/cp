#include<bits/stdc++.h>

using namespace std;

using ll = long long;

ll n, x, y;
string s;
vector<ll> X, Y;

bool check (ll len) {
    bool possible = false;
    // cout << " len " << len << '\n';
    ll tempx = 0, tempy = 0;
    for (ll i = 1; i + len <= n + 1; i++) {
        tempx = X[i-1] + X[n] - X[len + i -1];
        tempy = Y[i-1] + Y[n] - Y[len + i -1];
        ll diffx = x - tempx;
        ll diffy = y - tempy;
        // ll opx = x - X[n];
        // ll opy = y - Y[n];

        // cout << " tempx " << tempx;
        // cout << " tempy " << tempy;
        // cout << " diffx " << diffx;
        // cout << " diffy " << diffy;
        // // cout << " opx " << opx;
        // // cout << " opy " << opy;
        // cout << "\n";
        if((abs(diffx) + abs(diffy)) <= len && ((abs(diffx) + abs(diffy))%2 == len % 2) ){
            possible = true;   
        }

    }
    return possible;
}

void print() {
    for (auto &ch : X) cout << ch << " ";
    cout << '\n';
    for (auto &ch : Y) cout << ch << " ";
    cout << '\n';
}

void solve() {
    cin >> n;
    cin >> s;
    cin >> x >> y;
    X.assign(n+1,0);
    Y.assign(n+1,0);
    if ( abs(x) + abs(y) > n) {
        cout << -1 << '\n';
        return;
    }
   

    for (int i = 1; i <= n; i++) {
        if (s[i-1] == 'U') {
            X[i] = X[i-1];
            Y[i] = 1 + Y[i-1];
        }
        if (s[i-1] == 'D') {
            X[i] = X[i-1];
            Y[i] = -1 + Y[i-1];
        }
        if (s[i-1] == 'R') {
            X[i] = 1 + X[i-1];
            Y[i] = Y[i-1];
        }
        if (s[i-1] == 'L') {
            X[i] = -1 + X[i-1];
            Y[i] =  Y[i-1];
        }
    }
    if (x == X[n] && y == Y[n]) {
        cout << 0 << '\n';
        return;
    }
    // print();
    ll lo = 1, hi = n, ans = -1;

    while (hi >= lo) {
        ll mid = (hi + lo) / 2;
        if (check(mid)) {
            // cout << "OK\n";
            ans = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }

    cout << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();

    return 0;
}