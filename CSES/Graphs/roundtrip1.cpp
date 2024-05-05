#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int n, m, sv, ev;
vector<int> adj[200005];
vector<int> vis, par;
bool ok;

bool dfs(int u, int p) {
    vis[u] = 1;
    par[u] = p;
    for (auto &v : adj[u]) {
        if (v == p) continue;
        if (vis[v]) {
            sv = v;
            ev = u;
        }
        if (!vis[v]) if (dfs(v,u)) return true;
    }
    return false;
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
    ok = false;
    vis.assign(n+1,0);
    par.assign(n+1,-1);
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]){
            ok |= dfs(i, -1);
            if (ok) break;
        }
    }

    if (!ok) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> ans;
    int tv = ev;
    ans.push_back(ev);
    while(tv != sv) {
        ans.push_back(par[tv]);
        tv = par[tv];
    }
    ans.push_back(ev);
    cout << ans.size() << endl;
    for (auto c : ans) cout << c << " ";
    cout << "\n";
    return 0;

}