#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pi pair<int,int> 
#define pii pair<int,pi>
#define vii vector<pi>
#define viii vector<pii>
#define f first
#define s second

const int N = 100010;
const int inf = 1e16;
int n, m;
int dis[N];
bool vis[N];
vii adj[N];


void dij(int src,int (&dis)[],vii (&adj)[]) {
    priority_queue<pi> q;
    for (int i = 1; i < N; i++) dis[i] = inf;
    dis[src] = 0;
    q.push({0,src});
    memset(vis,0,sizeof(vis));
    while (!q.empty()) {
        int u = q.top().s;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v,w]: adj[u]) {
            if (dis[v] > (dis[u] + w)) {
                dis[v] = dis[u] + w;
                q.push({-dis[v],v});
            }
        }
    }
}

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
    
    
    return 0;
}