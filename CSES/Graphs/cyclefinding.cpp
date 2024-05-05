#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define pi pair<int,int>
#define vi vector<int>
#define vii vector<pi>

const int N = 2510;
int w[N][N];
vi adj[N], par(N,0), vis(N,0);
int n, m;

pi dfs(int u, int p) {
    if (vis[u]) return {u,p};
    vis[u] = 1;
    par[u] = p;
    for (auto v : adj[u]) {
        return dfs(v,u);
    }
    return {0,0};
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, we;
        cin >> u >> v >> we;
        adj[u].push_back(v);
        w[u][v] = we;
    }
    pi val = {0,0};
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
        val = dfs(i,0);
            if (val.first != 0 && val.second != 0) {
                int last = val.second;
                int parent = par[val.first];
                vector<int> ans;
                int cal = w[val.second][val.first];
                ans.push_back(val.first);
                while (last != parent) {
                    ans.push_back(last);
                    cal += w[par[last]][last];
                    last = par[last];
                }
                if (cal < 0) {
                    reverse(ans.begin(),ans.end());
                    cout << "YES\n";
                    for (auto a : ans) cout << a << " ";
                    return  0;
                }
            }
        val = {0,0};
        }
    }
    cout << "NO\n";
    return 0;
    

}