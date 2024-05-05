// #include<bits/stdc++.h>

// using namespace std;

// void solve() {
//     int n;
//     cin >> n;
//     vector<pair<int,int>> edges;

//     for (int i = 0; i < n - 1; i++) {
//         int a, b;
//         cin >> a >> b;
//         edges.push_back({a,b});
//     }
//     int readings = 0;
//     set<int> drawn = {1};
//     set<int> indices ;
//     while( drawn.size() != n-1) {
//         readings ++;
//         for( int i = 0; i < n-1; i++) {
//             if(find(indices.begin(), indices.end(),i) == indices.end()){
//                 int first = edges[i].first;
//                 int second = edges[i].second;

//                 if( find(drawn.begin(), drawn.end(), first) != drawn.end()) {
//                     //if first element exists
//                     drawn.insert(second);
//                     indices.insert(i);
//                 }
//                 if( find(drawn.begin(), drawn.end(), second) != drawn.end()) {
//                     //if second element exists
//                     drawn.insert(first);
//                     indices.insert(i);
//                 }
//             }
    
//         }
//     }
//     cout << readings + 1 <<"\n";

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
const int NMAX = 2e5 + 5;
int dp[NMAX], id[NMAX];
//dp to store the copil copac which was used to store the number of cc required to draw the ith index.
vector<pair<int,int>> edg[NMAX];

void dfs(int u) {
    for( auto it : edg[u]) {
        if(dp[it.first] == 0){
            dp[it.first] = dp[u] + (it.second <= id[u]);
            id[it.first] = it.second;
            dfs(it.first);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) dp[i] = id[i] = 0, edg[i].clear();
    for(int i = 1; i < n; i++) {
        int a,b;
        cin >> a >> b;
        edg[a].push_back({b,i});
        edg[b].push_back({a,i});
    }

    dp[1] = 1;
    dfs(1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    } 
    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}