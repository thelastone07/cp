#include <bits/stdc++.h>
 
using namespace std;
using ll = long long ;
const int SZ = 200005;
vector<int> adj[SZ];
int S[SZ];
 
int n;
 
void dfs(int u, int l, int p) {
    S[u] = 1;
    for (int v: adj[u]) {
        if (v != p) {
            dfs(v,l+1,u);
            S[u] += S[v];
        }
    }
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    
    dfs(1, 0, 0);
    for (int i = 1; i <= n; i++) {
        cout << S[i] - 1 << " ";
    }
    cout << '\n';
    return 0;
    
    
}