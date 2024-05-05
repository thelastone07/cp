#include<bits/stdc++.h>

using namespace std;
int n, k;
vector<int> a;
int cnt;

void print (vector<int> arr) {
    for (auto &x : arr) cout << x << " ";
    cout << '\n';
}

void back_tracking(int level, vector<int>& arr) {
    
    if (level == n) {
        // cout << cnt << " ";
        // cout << "\n";
        cnt++;
        if (cnt == k) {
            print(arr);
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i]){
            a[i]--;
            arr.push_back(i);
            back_tracking(level+1,arr);
            a[i]++;
            arr.pop_back();
        }
    }
}

void solve() {
    cin >> n >> k;
    a.resize(n+1,1);
    // for (int i = 1; i <= n; i++) a[i] = 1;
    vector<int> arr;
    cnt = 0;
    back_tracking(0,arr);
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);    
    solve();
    return 0;
}