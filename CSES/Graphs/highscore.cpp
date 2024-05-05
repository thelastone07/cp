#include<bits/stdc++.h>
using namespace std;
 
#define int long long int
#define vi vector<int>
#define pi pair<int,int>
#define pii pair<int,pi>
#define vii vector<pi>
 
const int INF = 9e17;
const int NINF = (-1) * INF;
const int N = 100010;
const int M = 200010;
int n, m;
vi dis, disc, vis;
vii adj[N];
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v,w });
    }
    vis.resize(n + 1, 0);
    dis.resize(n + 1, INF);
    disc.resize(n + 1, INF);
    dis[1] = 0;
    disc[1] = 0;
 
    priority_queue<pii> q;
    q.push({ 0,{1,0} });
    while (!q.empty()) {
        int u = q.top().second.first;
        int flag = q.top().second.second;
        int d = -q.top().first;
        q.pop();
        for (auto [v, w] : adj[u]) {
 
            if (flag == 0) {
                if (dis[u] < d) continue;
                if (disc[v] > (d + w / 2)) {
                    disc[v] = d + w / 2;
                    q.push({ -disc[v],{v,1} });
                }
                if (dis[v] > (d + w)) {
                    dis[v] = d + w;
                    q.push({ -dis[v],{v,0} });
                }
            }
            if (flag == 1) {
                if (disc[u] < d) continue;
                if (disc[v] > (d + w)) {
                    disc[v] = d + w;
                    q.push({ -disc[v],{v,1} });
                }
            }
        }
    }
 
    cout << disc[n] << '\n';
 
}