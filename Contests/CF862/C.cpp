#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> k(n,0);
    int a[m], b[m], c[m];
    for ( int i = 0; i < n; i++) {
        cin >> k[i];
    }
    for( int i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    //sort and make unique
    sort(k.begin(), k.end());
    auto ip = unique(k.begin(), k.end());
    k.resize(distance(k.begin(), ip));

    for ( int i = 0 ; i < m ; i++) {
        if ( c[i] < 0) {
            cout << "NO" <<"\n";
            continue;
        }
        else {
            float product = sqrt(a[i] * c[i]) * 2;
            float min_k = b[i] - product;
            float max_k = b[i] + product;
            int low, high;
            //exclusive
            if( roundf(product) == product){
                low = min_k;
                high = max_k;
            }
            else{
                low = floor(min_k);
                high = ceil(max_k);
            }
            int it1 = lower_bound( k.begin(), k.end(), high) - k.begin();
            int it2 = upper_bound( k.begin(), k.end(), low) - k.begin();
            //iterators pointing to different 
            if(it1 - it2 >= 0) {
                auto it = upper_bound(k.begin(), k.end(), low);
                cout << "YES\n";
                cout << *it <<"\n";
                continue;
            }
            else {
                cout << "NO\n";
                continue;
            }
        }
        cout << "\n";

    }
}

signed main() {
    ios :: sync_with_stdio (false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while ( t-- ) {
        solve();
    }
}