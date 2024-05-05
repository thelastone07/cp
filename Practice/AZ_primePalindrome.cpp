#include<bits/stdc++.h>

using namespace std;

int a,b;
int ans;

bool check(string str) {
    const regex pattern("^0+(?!$)");
    str = regex_replace(str, pattern, "");
    int n = stoi(str);
    if (!(a <= n && n <= b)) return false;
    if (n == 1) return false;
    int i = 2;
    while (i*i <= n) {
        if (n % i == 0) {
            return false;
        }
        i += 1;
    }
    return true;
}

void back_tracking(int level, string s) {
    if (level > log10(b) + 1) return;
    if (level == log10(b) + 1){
        if (check(s)) ans++;
        return;
    }
    if (level == 0) {
        for (int i = 0; i <=9; i++) {
            s = to_string(i) + to_string(i);
            back_tracking(level+2, s);
            s = to_string(i);
            back_tracking(level+1, s);
        }
    }
    for (int i = 0; i <= 9; i++) {
        string str = s;
        str = to_string(i) + str + to_string(i);
        back_tracking(level+2,str);
        back_tracking(level,s);
    }

}

void solve() {
    cin >> a >> b;
    // cout << "a" << a;
    // cout << "b" << b;
    string s = "";
    ans = 0;
    back_tracking(0, s);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}