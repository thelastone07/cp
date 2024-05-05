#include<bits/stdc++.h>
using namespace std;

bool valid(int x, int y, int n, int m){
    if( x >=0 && x < n && y >= 0 && y < m) return true;
    return false;
}

void dfs(int x, int y, int n, int m, vector<vector<char>> &adj, vector<vector<int>> &visited) {
    int X[] = {-1, 1, 0, 0};
    int Y[] = {0, 0, 1, -1};
    for(int i = 0; i < 4; i++){
        int x_ = x - X[i];
        int y_ = y - Y[i];
        if( valid(x_, y_, n, m) && adj[x_][y_] == '.' && visited[x_][y_] == -1){
            visited[x_][y_] = 1;
            dfs(x_, y_, n, m, adj, visited);
        }
    }    
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> adj(n,vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> adj[i][j];
        }
    }
    int floors = 0;
    vector<vector<int>> visited(n,vector<int>(m,-1));

    for (int i = 0; i < n; i++) {
        for( int j = 0; j < m; j++) {
            if(visited[i][j] == -1 && adj[i][j] == '.') {
                visited[i][j] = 1;
                floors++;
                dfs(i, j, n, m, adj, visited);
            }
        }
    }

    cout << floors <<"\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    solve();
    return 0;
}