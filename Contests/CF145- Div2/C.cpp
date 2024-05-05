#include<bits/stdc++.h>
#define ll long long

using namespace std;

void subarray(){
    int n, k;
    cin>>n>>k;
    int x = 0;
    while((x + 1)*(x + 2)/2 <= k){
        x += 1;
        //number of positive sub arrays
    }
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        if (i < x) {
            a[i] = 2;
        }   else if (i == x) {
            a[i] = -2 * x -1 + 2 * (k - x * (x + 1) / 2);
        } else{
            a[i] = -1000;
        }
        cout << a[i] << " \n"[i == n-1];

    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int T;
    cin>>T;

    while(T--){
        subarray();
    }
    return 0;
}