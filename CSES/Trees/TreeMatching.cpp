#include <bits/stdc++.h>
 
using namespace std;
using ll = long long ;
const int SZ = 200005;
vector<int> adj[SZ];
 
vector<int> marked;
 
int n;
int cnt;
 
void dfs(int u, int l, int p) {
    
    for ( auto v : adj[u]) {
        if (v != p) {
            dfs(v,l+1,u);
            
        }
    }
    // cout << "U " << u << " P " << p << " mark " << marked[u] << marked[p] << "\n";
    if (!marked[u] && !marked[p] && p != 0) {
        // cout << "in";
        cnt++;
        marked[u] = 1;
        marked[p] = 1;
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
    
    marked.assign(n+1,0);
    cnt = 0;
    
    dfs(1,0,0);
    
    cout << cnt << '\n';
    return 0;
    
    