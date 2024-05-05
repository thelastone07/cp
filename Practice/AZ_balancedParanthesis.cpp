#include<bits/stdc++.h>

using namespace std;
int n, k;

void back_tracking(int level,  int var, int mx, string& str) {
    if (var < 0) return ;

    if (level == n) {
        if(mx == k && var == 0) {
            cout << str << "\n";
            return;
        }
        return;
    }

    str.push_back('(');
    back_tracking(level+1,  var + 1, max(mx, var + 1),str);
    str.pop_back();
    str.push_back(')');
    back_tracking(level+1,  var - 1, max(mx, var - 1),str);

}

void solve() {
    cin >> n >> k;
    string str;
    back_tracking(0,0,0,str);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}