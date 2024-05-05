// #include<bits/stdc++.h>

// using namespace std;

// int LCM( int a, int b) {
//     int greater = max(a, b);
//     int smallest = max(a, b);
//     for ( int i = greater; ; i += greater) {
//         if ( i % smallest == 0)
//             return i;
//     }
// }

// void solve() {
//     int n;
//     cin >> n;

//     if (n == 1) cout << "1\n";

//     int a[n], sum = 1;
//     a[0] = 1;
    
//     for( int i = 1; i < n; i++) {
//         a[i] = LCM(a[i-1], i+1);
//         sum += a[i];
//     }

//     a[0] += sum%n;

//     for(int i = 0; i < n; i++) {
//         cout << a[i] <<" \n"[i == n-1];
//     }


// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);

//     int t;
//     cin >> t;

//     while(t--) {
//         solve();
//     }
// }

#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int a[n], sum = 0;
    
    for (int i = 0; i < n; i++) {
        a[i] = i+1;
        sum += a[i];
    }
    a[0] += sum%n;

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n-1];
    }
}

signed main() {
    ios :: sync_with_stdio (false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}