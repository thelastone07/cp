#include<bits/stdc++.h>

using namespace std;

void solve() {
    long long n, k, g;
    cin >> n >> k >> g;
    long long saved = min((g - 1) / 2* n, k*g);
    long long rest = (k * g - saved) % g;

    if (rest > 0) {
        saved -= (g - 1) / 2;
        long long last = ((g - 1) / 2 + rest) % g;

        if (last * 2 < g) {
            saved += last;
        } else {
            saved -= g - last;
        }
    }


    cout << saved << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long t;
    cin >> t;
    while (t--) solve();

    return 0;
}