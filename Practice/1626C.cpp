#include<bits/stdc++.h>

using namespace std;

vector<int> k, h_;
vector<pair<int,int>> intervals;

void update() {
    int sz = intervals.size();
    if (sz == 1) return;
    pair<int,int> b = intervals[sz-1];
    pair<int,int> a = intervals[sz-2];
    if ( a.second >= b.first ) {
        //if a and b are inclusive delete both and pushback common interval
        // update again.
        pair<int,int> c;
        c.first = min(a.first, b.first);
        c.second = b.second;
        intervals.pop_back();
        intervals.pop_back();
        intervals.push_back(c);
        update();
    } 
}

long long calculate() {
    int sz = intervals.size();

    long long ans = 0;

    for (int i = 0; i < sz; i++) {
        long long n = intervals[i].second - intervals[i].first + 1;
        ans += n * (n + 1) / 2;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;

    intervals.clear();
    k.resize(n);
    h_.resize(n);

    for (int i = 0; i < n; i++) cin >> k[i];
    for (int i = 0; i < n; i++) cin >> h_[i];

    /*
    Algorithm: start from 0 to n monsters.
    push intervals.
    Get exclusive intervals and use sum of natural numbers
    of lenght of all exclusive intervals
    */

    int ans = 0;


    for (int i = 0; i < n; i++) {
        int t = k[i];
        int h = h_[i];

        intervals.push_back({t-h+1,t});
        update();
    }

    cout << calculate() << "\n";

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}