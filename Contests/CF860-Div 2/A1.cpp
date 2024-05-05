#include<bits/stdc++.h>

using i64 = long long;
using namespace std;

void showstopper() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] > a[n - 1] || b[i] > b[n - 1]) {
            swap(a[i], b[i]);
        }
        if (a[i] > a[n - 1] || b[i] > b[n - 1]) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        showstopper();
    }
}