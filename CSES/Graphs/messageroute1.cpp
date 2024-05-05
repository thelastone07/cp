#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int n, m;
vector<int> adj[200005];
vector<int> vis;
vector<int> par;

void bfs(int src) {
    queue<int> q;
    q.push(src);
    par[src] = -1;
    while(!q.empty()) {
        int u = q.front();
        vis[u] = 1;
        q.pop();

        for (auto v : adj[u]) {
            if (!vis[v] && par[v] == -1){
                q.push(v);
                par[v] = u;
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
    par.resize(n+1,-1);

    bfs(1);
    if (!vis[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> ans;
    int last = n;
    while (last != 1) {
        ans.push_back(last);
        last = par[last];
    }
    ans.push_back(1);
    cout << ans.size() << '\n';
    reverse(ans.begin(),ans.end());
    for (auto &a : ans) cout << a << " ";
    cout << "\n";
    return 0;

}