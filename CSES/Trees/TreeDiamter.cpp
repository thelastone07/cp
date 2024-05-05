#include <bits/stdc++.h>
 
using namespace std;
using ll = long long ;
const int SZ = 200005;
vector<int> adj[SZ];
int n;
int depth[SZ];
int par[SZ];
int cnt;
 
 
void dfs(int u, int l, int p) {
    depth[u] = l;
    par[u] = p;
    cnt = max(cnt,l);
    for ( auto v : adj[u]) {
        if (v != p) {
            dfs(v,l+1,u);
            
        }
    }
    
}
 
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
    
    cnt = 0;
    dfs(1,1,0);
    // cout << "cnt " << cnt << '\n';
    for (int i = 1; i <=n; i++) {
        if (depth[i] == cnt){
            // cout << "i "<< i << '\n' << ;
            cnt = 0;
            dfs(i,0,0);
            break;
        }
    }
    
    cout << cnt << '\n';
    
    
    
}
