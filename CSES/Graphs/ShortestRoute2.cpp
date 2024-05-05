#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505;
int dis[N][N];

void solve() {
    int n,m,q;
    cin >> n >> m >> q;
    int M = 1000000000000;
    for (int i = 1; i <= n; i++) 
    for (int j = 1; j <= n; j++)
        dis[i][j] = M;

    for (int i = 0; i < m; i++) {
        int u,v,w ;
        cin >> u >> v >> w;
        dis[u][u] = 0;
        dis[v][v] = 0;
        dis[u][v] = min(dis[u][v],w);
        dis[v][u] = min(dis[v][u],w);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a,b;
        cin >> a >> b;
        if (dis[a][b] < M) cout << dis[a][b] << '\n';
        else cout << "-1\n";
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}