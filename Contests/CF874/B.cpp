// // #include<bits/stdc++.h>

// // using namespace std;

// // void solve() {
// //     int n, k;
// //     cin >> n >> k;
// //     vector<int> a(n,0), b(n,0);
// //     for(int i = 0; i < n; i++) {
// //         cin >> a[i];
// //     }
// //     for(int i = 0; i < n; i++) {
// //         cin >> b[i];
// //     }
// //     sort(b.begin(), b.end());
// //     vector<int> c(n,0);
// //     set<int> s;
// //     for(int i = 0; i < n; i++) {
// //         auto it1 = upper_bound(b.begin(), b.end(), a[i] - k) - b.begin();
// //         auto it2 = lower_bound(b.begin(), b.end(), a[i] + k) - b.begin();
// //         if(it1 != n && s.find(it1) == s.end()){
// //             s.insert(it1);
// //             c[i] = b[it1];
        
// //         }
// //         if(it2 != n && s.find(it2) == s.end()){
// //             s.insert(it2);
// //             c[i] = b[it2];
// //         }
// //     }
// //     for ( int i = 0; i < n; i++) {
// //         cout << c[i] <<" \n"[i == n - 1];
// //     }
// // }

// // signed main() {
// //     ios::sync_with_stdio(false);
// //     cin.tie(0); cout.tie(0);

// //     int t;
// //     cin >> t;

// //     while(t--){
// //         solve();
// //     }
// //     return 0;
// // }



#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> a(n,{0,0});
    int b[n];
    
    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a[i] = {temp, i};
    }
    for ( int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(b, b+n);
    sort(a.begin(), a.end());

    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        ans[a[i].second] = b[i];
    }
    for( auto &i : ans) cout << i <<" ";
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}
