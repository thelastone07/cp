#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int n, m;
string adj[1001];
vector<vector<int>> vis;
int X[] = {0, 0 , 1 , -1};
int Y[] = {1, -1, 0, 0};

// 0 - R  1 - L  2 - D  3 - U

bool valid(int i, int j) {
    if ( i < 0 || i >= n || j < 0 || j >= m) return false;

    if (adj[i][j] == '#') return false;
    return true;
}

void dfs(int i, int j) {
    vis[i][j] = 1;
    for (int k = 0; k < 4; k++) {
        int x = X[k] + i;
        int y = Y[k] + j;
        if (valid(x,y) && !vis[x][y] ) dfs(x,y);
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    // cout << "start";
    for (int i = 0; i < n; i++) cin >> adj[i];
    // cout << "done";
    vis.assign(n,vector<int>(m,0));

    int cnt = 0;

    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (valid(i,j) && !vis[i][j] ) {
        dfs(i,j);
        cnt++;
    }
    cout << cnt << '\n';
    return 0;
}