// #include<bits/stdc++.h>

// using namespace std;

// vector<int> a;
// map<int,int> cnt;
// map<int,int> sm;
// int n, mex;


// int find_min(int i) {
//     if (cnt[i] && i < mex) return cnt[i];
//     if (i == mex) return 0;
//     else {
//         if (sm[i] >= i) {
//             int val = 0;
//             if (cnt[i]) val += cnt[i];

            
//             return val;
//         }
//         else {
//             return -1;
//         }
//     }
    
// }

// void solve() {
//     cin >> n;

//     cnt.clear();
//     sm.clear();
//     a.clear();
//     a.resize(n);

//     for (int i = 0; i < n; i++){
//         cin >> a[i];
//         cnt[a[i]]++;
//     }
//     sort(a.begin(), a.end());
//     for (int i = 0; i <= n; i++) {
//         if (!cnt[i]) {
//             mex = i;
//             break;
//         }
//     }
//     for (int i = 0; i <= n; i++) {
//         for (int j = i - 1 ; j >= 0; j--) {
//             if (cnt[j]) {
//                 sm[i] += cnt[j];
//             }
//         }
//     }

//     for (int i = 0; i <= n; i++) cout << find_min(i) << " \n"[i == n];

// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);

//     int t;
//     cin >> t;

//     while (t--) {
//         solve();
//     }

//     return 0;
// }

#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), cnt(n+1,0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a.begin(), a.end());
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}