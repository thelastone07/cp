#include <bits/stdc++.h>

using namespace std;
using ll = long long;



void solve() {
    
    int n;
    cin >> n;

    vector<int> b(n), a(n);

    ll sumb = 0;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        sumb += b[i];
    }

    ll d = n * 1ll * (n + 1) / 2;

    if(sumb % d != 0) {
        cout << "NO" << endl;
        return;
    }

    ll suma = sumb / d;

    for(int i = n - 1; i >= 0; i--) {
        ll res = (b[i] - b[(i + 1) % n] + suma);
        if(res % n != 0 || res <= 0) {
            cout << "NO" << endl;
            return;
        }

        a[(i + 1) % n] = res / n;
    }

    cout << "YES" << endl;
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}