#include<bits/stdc++.h>

using namespace std;
vector<string> board;
vector<vector<int>> pos;
int ans;

// bool valid(vector<pair<int,int>> pos) {
//     vector<vector<int>> a(8, vector<int>(8,0));
//     bool ok = true;
//     for (auto &it : pos) {
//         int i = it.first;
//         int j = it.second;
//         for (int k = 0; k < 8; k++) if ( k != i) a[k][j] = -1;
//         for (int k = 0; k < 8; k++) if ( k != j) a[i][k] = -1;
//         int min_ = min(i,j);
//         int x = i - min_;
//         int y = j - min_;
//         for (; x < 8 && y < 8;) {
//             if (x != i && y != j) a[x][y] = -1;
//             x++;
//             y++;
//         }
//     }
//     for (auto &it : pos) {
//         int i = it.first;
//         int j = it.second;
//         if (a[i][j] == -1) ok = false;
//     }
//     return ok;
// }

// void back_tracking(int level, vector<pair<int,int>> &pos) {
//     if (level == 8) {
//         if ( valid(pos)) ans++;
//         return;
//     }
//     for (int i = 0; i < 8; i++) {
//         for (int j = 0; j < 8; j++) {
//             if (board[i][j] == '.')
//                 pos.push_back({i,j});
//                 board[i][j] == '*';
//                 back_tracking(level+1, pos);
//                 board[i][j] == '.';
//                 pos.pop_back();
//                 back_tracking(level,pos); 
//         }
//     }
// }


bool check(int i, int j) {
    if (board[i][j] == '*') return false;
    for (int x = i, y = j - 1; j >= 0; j--) if (pos[x][y] == 1) return false;

    for (int x = i - 1, y = j - 1; x >= 0 && y >= 0;){
        if (pos[x][y] == 1) return false;
        x--; y--;
    }
    for (int x = i - 1, y = j + 1; x >= 0 && y <= 7;){
        if (pos[x][y] == 1) return false;
        x--; y++;
    }
    return true;
}

void back_tracking(int level) {
    if (level == 8) {
        ans++;
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (check(level,i)) {
            pos[level][i] = 1;
            back_tracking(level+1);
            pos[level][i] = 0;
        }
    }
}


void solve(){
    board.resize(8);
    for (int i = 0; i < 8; i++)cin >> board[i];
    ans = 0;
    // vector<pair<int,int>> pos;
    pos.resize(8, vector<int>(8,0));
    back_tracking(0);
    cout << ans << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}