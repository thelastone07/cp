#include<bits/stdc++.h>

using namespace std;
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>


int n,m;
int vis[100005];
long long dis[100005];
vii adj[200005];


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
    }
    for (int i = 2; i <= n; i++) dis[i] = LLONG_MAX;
    priority_queue<pii,vii,greater<pii>> q;
    q.push({0,1});
    while (!q.empty()) {
        int u = q.top().second;
        q.pop();
        if (vis[u])continue;
        vis[u] = 1;
        for (auto [v,w]:adj[u]) {
            if (dis[v] > (dis[u] + w)) {
                dis[v] = dis[u] + w;
                q.push({dis[v],v});
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << dis[i] << " \n"[i == n];
}