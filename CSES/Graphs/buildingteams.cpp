#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int n, m;
vector<int> adj[200006];
vector<int> vis;
vector<int> team;
bool ok;

void dfs(int src, int c) {
    team[src] = c;
    vis[src] = 1;
    for (auto v : adj[src]) {
        if (!vis[v])dfs(v, !c);
        else {
            if (team[v] == c) {
                ok = false;
                return;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis.resize(n+1,0);
    team.resize(n+1,0);
    ok = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i,0);
    }
    
    if (!ok) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) cout << (team[i] == 0 ? 1 : 2) << " ";
    cout << '\n';
}