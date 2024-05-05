#include<bits/stdc++.h>

using namespace std;
int n;
vector<int> a;
map<int,int> mp;

void back_tracking(int level, vector<int> &temp) {
    if (level == n) {
        for (auto &it : temp) 
        cout << it << " ";
        cout << "\n";
        return;
    }
    for (auto it : mp) {
        if (it.second != 0) {
            temp.push_back(it.second);
            mp[it.first]--;
            back_tracking(level+1, temp);
            mp[it.first]++;
            temp.pop_back();
        }
    }
}

void solve() {
    cin >> n;
    a.clear();
    a.resize(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    vector<int> v;
    back_tracking(0,v);


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
