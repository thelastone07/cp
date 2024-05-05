#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int n, m, sx, ex, sy, ey;
string adj[1001];
vector<vector<int>> vis;
vector<vector<pair<int,int>>> par;
int X[] = {0, 0 , 1 , -1};
int Y[] = {1, -1, 0, 0};

// 0 - R  1 - L  2 - D  3 - U

bool valid(int i, int j) {
    if ( i < 0 || i >= n || j < 0 || j >= m) return false;
    if (adj[i][j] == '#') return false;
    return true;
}

void bfs(pair<int,int> s) {
    queue<pair<int,int>> q;
    q.push(s);
    
    vis[s.first][s.second] = 1;
    // int cnt = 0;
    // cout << "I" << s.first << '\n';
    // cout << "J" << s.second << '\n';
    while (!q.empty()) {
        // cnt++;
        int topx = q.front().first;
        int topy = q.front().second;
        // cout << "topx" << topx << '\n';
        // cout << "topy" << topy << '\n'; 
        q.pop();
        for (int k = 0; k < 4; k++) {
            int x = topx + X[k];
            int y = topy + Y[k];
            // cout << " X " << x << " y " << y << '\n';
            // cout << valid(x,y) << " \n";
            if (valid(x,y) && !vis[x][y]) {
                q.push({x,y});
                par[x][y] = {topx,topy};
            }

        }
    }
    // cout << "cnt" << cnt << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    // cout << "start";
    for (int i = 0; i < n; i++){ 
        cin >> adj[i];
        for (int j = 0; j < m; j++) {
            if (adj[i][j] == 'A') {
                sx = i;
                sy = j;
            }
            if (adj[i][j] == 'B') {
                ex = i;
                ey = j;
            }
        }
    }
    // cout << "done";
    vis.assign(n,vector<int>(m,0));
    par.resize(n,vector<pair<int,int>>(m,{-1,-1}));
    
    bool ok = false;
    bfs({sx,sy});
    if (vis[ex][ey]) ok = true;

    // for (auto &a: par) {
    //     for (auto &b : a) {
    //         cout << b.first << " " << b.second << " ";
    //     }
    //     cout << "\n";
    // }

    if (!ok) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    vector<char> ans;
    while (par[ex][ey].first != sx && par[ex][ey].second != sy) {
        pair<int,int> p = par[ex][ey];
        int x = p.first;
        int y = p.second; 

        if ((ex - x) == 1) ans.push_back('D');
        if ((ex - x) == -1) ans.push_back('U');
        if ((ey - y) == 1) ans.push_back('R');
        if ((ey - y) == -1) ans.push_back('L');
        ex = x;
        ey = y;
    }
    reverse(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for (auto &a : ans) cout << a;
    cout << '\n';


    return 0;
}