#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int n, m;
vector<int> adj[200006];
vector<int> vis;

void dfs(int src) {
    vis[src] = 1;
    for (auto v : adj[src]) {
        if (!vis[v])dfs(v);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis.resize(n+1,0);
    vector<int> ans;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            ans.push_back(i);
        }
    }

    cout << ans.size() - 1 << "\n";

    for (int i = 1; i < ans.size(); i++) cout << ans[0] << " " << ans[i] << '\n';
    return 0;
}