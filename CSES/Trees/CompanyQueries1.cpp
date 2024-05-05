#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
const int SZ = 200005;
int n, q, depth[SZ];
vector<int> adj[SZ];
int par[21][SZ];
 
void dfs(int node, int p, int d) {
    depth[node] = d;
    par[0][node] = p;
    
    for (auto v : adj[node]) {
        if (v != p) dfs(v,node,d+1); 
    }
}
 
void preprocess() {
    dfs(1,-1,0);
    
    for (int i = 1; 1 << i <= n; i++) 
    for (int j = 0; j <= n; j++) 
    par[i][j] = par[i-1][par[i-1][j]];
}
 
int LCA(int x, int y) {
    if (depth[x] < depth[y])
        swap(x,y);
        
    for (int i = 0;  i < 21; i++) 
        if ((depth[x] - depth[y]) & ( 1 << i))
            x = par[i][x];
    
    if (x == y){
        return x;
    }
    
    for (int i = 20; i >= 0; i--) {
        if (par[i][x] != par[i][y]) {
            x = par[i][x];
            y = par[i][y];
        }
    }
    return par[0][x];
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    preprocess();
    while (q--) {
        int u, k;
	cin >> u >> k;
	int boss = u;
	for (int i = 0; i < 21; i++ )
		if (k & (1 << i))
			boss = par[i][boss];
 
     cout << (boss == 0 ? -1 : boss ) << '\n';
    }
 
    
}