#include<bits/stdc++.h>

using namespace std;
int n;
int ans;
vector<int> v;

// 2 1
// 4 2
// 6 2
// n = 19

bool isPrime(int a, int b) {
    int sum = a + b;
    if ( (sum == 3) || (sum == 5 ) || (sum == 7 )|| (sum == 11) || (sum == 13)
    || (sum == 17) || (sum == 19) || (sum == 23) || (sum == 29) || (sum == 31)
    || (sum == 37) )
    return true;
    
    return false;
}

void print(vector<int> arr) {
    for (auto &x: arr) cout << x << " ";
    cout << "\n";
}
void back_tracking(int level, vector<int>&arr, int last = 0) {
    if (level == n) {
        // print(arr);
        ans++;
        return;
    }
    if (level == 0) {
        arr.push_back(1);
        back_tracking(1,arr, 1);
    }else if ( last%2 == 1)
    for (int i = 2; i <= n; i+=2) {
        if (v[i] && isPrime(i,last)) {
            bool ok = true;
            if (level == (n - 1)) {
                if (isPrime(i,1)) {
                    ok = true;
                }else ok = false;
           }

           if (ok) {
            v[i]--;
            arr.push_back(i);
            back_tracking(level+1,arr, i);
            arr.pop_back();
            v[i]++;
           }
        }
    }
    else {
        for (int i = 3; i <= n; i+=2) {
        if (v[i] && isPrime(i,last)) {
            bool ok = true;
            if (level == (n - 1)) {
                if (isPrime(i,1)) {
                    ok = true;
                }else ok = false;
           }

           if (ok) {
            v[i]--;
            arr.push_back(i);
            back_tracking(level+1,arr, i);
            arr.pop_back();
            v[i]++;
           }
        }
    }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if (n%2) {
        cout << 0 << "\n";
        return 0;
    }
    ans = 0;
    v.resize(n+1,1);
    vector<int> arr;
    back_tracking(0, arr);
    cout << ans << "\n";
    return 0;
}