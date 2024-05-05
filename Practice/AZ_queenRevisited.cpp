#include<bits/stdc++.h>

using namespace std;
int n, ans;
vector<int> col;

bool check(int r, int c) {
    
    for (int i = 0; i < r; i++) {
        if (col[i] == c || (col[i] + i) == (r + c) || (col[i] - i) == (c - r)) return false;
    }
    for (int i = r-1; i >=0 && i >= r-2; i--) {
        int c1 = c - (i - (r-1) + 2), c2 = c + (i - (r-1) + 2);
        if ( c1 >= 0 && c1 < n) {
            if (col[i] == c1) return false;
        }
        if ( c2 >= 0 && c2 < n) {
            if (col[i] == c2) return false;
        }
    }
    return true;
}

void back_tracking(int level) {
    if (level == n) {
        ans++;
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (check(level,i)){
            col.push_back(i);
            back_tracking(level+1);
            col.pop_back();
        }
    }
}

void solve() {
    cin >> n;
    ans = 0;
    back_tracking(0);
    cout << ans <<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}