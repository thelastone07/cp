#include<bits/stdc++.h>

using namespace std;

void three7s() {
    int m;
    cin >> m;
    vector<vector<int>> a;
    for ( int i = 0 ; i < m; i++) {
        int n;
        cin >> n;
        // cout << "first loop enterd\n";
        vector<int> ai;
        for ( int j = 0; j < n; j++){
            // cout << "second loop entered\n";
            int temp;
            cin >> temp;
            ai.push_back(temp);
        }
        // cout << "scond loop exit\n";
        a.push_back(ai);
    }
    // return;
    vector<int> ans(m,-1);
    if( m == 1)cout << a[0][0] << "\n";
    ans[m-1] = a[m-1][0];
    for( int i = 0 ; i <= m-2; i++) {
        //check if elements of i is present in i+1 to m
        for( auto c : a[i]){
            int cnt = 0;
            for ( int j = i+1 ; j < m; j++){
                cnt += count( a[j].begin(), a[j].end(), c);   
            }
            if(cnt == 0) {
                ans[i] = c;
                break;
            }
        }
        if( ans[i] == -1){
            cout << "-1\n";
            return;
        }
        
    }
    for( int i = 0; i < m; i++) {
        cout << ans[i] << " \n"[ i == m-1];
    }
    
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while( t--) {
        three7s();
    }
    return 0;
}