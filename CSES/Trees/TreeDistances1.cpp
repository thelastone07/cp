#include <bits/stdc++.h>
 
using namespace std;
using ll = long long ;
const int SZ = 200005;
vector<int> adj[SZ];
int n;
vector<int> outdp;
vector<pair<int,int>> indp;
 
 
void indfs(int u, int p) {
    indp[u].first = 0;
    indp[u].second = 0;
    for (auto v : adj[u]) {
        if (v != p) {
            indfs(v,u);
            
            if ((indp[v].first + 1) > indp[u].first) {
                indp[u].second = indp[u].first;
                indp[u].first = 1 + indp[v].first;
                
            }
            else if ((indp[v].first + 1) > indp[u].second) {
                indp[u].second = 1 + indp[v].first;
            }
        }
    }
}
 
void outdfs(int u, int p, int val) {
    outdp[u] = val;
    
    for (auto v : adj[u]) {
        if (v != p) {
            int temp = 1 + val;
            
            if( (indp[u].first) == (indp[v].first + 1)) {
                temp = max(temp, indp[u].second + 1);
            }
            else temp = max(temp,indp[u].first + 1);
            outdfs(v,u,temp);
        }
    }
}
 
 
 
 
// void dfs(int u, int l, int p) {
//     depth[u] = l;
//     par[u] = p;
//     cnt = max(cnt,l);
//     for ( auto v : adj[u]) {
//         if (v != p) {
//             dfs(v,l+1,u);
            
//         }
//     }
// }
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    for (int i = 2; i <= n; i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    outdp.resize(n+1,0);
    indp.assign(n+1,pair<int,int>());
    indfs(1,0);
    outdfs(1,0,0);
    
    for (int i = 1; i <= n; i++) {
        cout << max(indp[i].first,outdp[i]) << " ";
    }
    
    
    
}