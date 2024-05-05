#include<bits/stdc++.h>

using namespace std;

/*
Perform BFS on monsters.
You have the time now.
Perform BFS on man now, and check if the time taken is less than 
that of man, then it is valid.
If exit point is not visitd, then impossible

*/

vector<int> dx = {0,0,1,-1};
vector<int> dy = {1,-1,0,0};
//  r,l ,d,u
vector<vector<bool>> vis;
vector<string> adj;
vector<pair<int,int>> monsters, exitts;
pair<int,int> human;
vector<vector<pair<int,int>>> par;
vector<vector<int>> mdist, hdist;
 
int n, m;

bool isValid(int x, int y) {
    if( x < 0 || x >=n || y < 0 || y >= m ) return false;
    if (adj[x][y] == 'M' || adj[x][y] == '#') return false;
    if (vis[x][y]) return false;
    return true;  
}

void bfs(int i, int j,string s) {
    if (s == "monster") {
        queue<pair<int,int>> q;
        q.push({i,j});

        while(!q.empty()) {
            pair<int,int> a = q.front();
            q.pop();
            int u = a.first, v = a.second;
            for (int z = 0; z < 3; z++) {
                mdist[]
            }
        }

    } else {

    }
}

void initialize() {
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) {
            char c = adj[i][j];

            if (c == 'M') monsters.push_back({i,j});
            if (c == 'A') human = {i,j};
            if (c == '.') exitts.push_back({i,j});
        }
}

void solve() {
    cin >> n >> m;

    adj.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> adj[i];
    }

    initialize();

    for (auto &monster : monsters) {
        bfs(monster.first, monster.second, "monster");
    }

    bfs(human.first, human.second, "human");

    bool ok = false;

    pair<int,int> e;

    for (auto &exitt : exitts)
        if (vis[exitt.first][exitt.second]) ok = true, e = exitt;

    if (!ok) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    while (e != human) {
        int i = e.first, j = e.second;
        int pi = par[i][j].first, pj = par[i][j].second;

        int dx = i - pi;
        int dy = j - pj;

        if ( dx == 0 && dy == 1) cout << "R";
        if ( dx == 0 && dy == -1) cout << "L";
        if ( dx == 1 && dy == 0) cout << "D";
        else cout << "U";
    }

    cout << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();

    return 0;
}
