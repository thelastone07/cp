// n = 9
// 1 9
//2 56

#include<bits/stdc++.h>

using namespace std;
int n;
int ans;
int curr;
vector<vector<int>> neigh;

void back_tracking(int level, string s) {

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    neigh.resize(n+1);
    for (int i = 1; i <= 9; i++) {
        if ( i == 1){
            neigh[i]={2,4,5,6,8};
        }
        if ( i == 2){
            neigh[i]={1,3,4,5,6,7,9};
        }
        if ( i == 3){
            neigh[i]={2,4,5,6,8};
        }
        if ( i == 4){
            neigh[i]={1,2,3,5,7,8,9};
        }
        if ( i == 5){
            neigh[i]={1,2,3,4,6,7,8,9};
           }
        if ( i == 6){
            neigh[i]={};
        }
        if ( i == 7){
            neigh[i]={};
        }
        if ( i == 8){
            neigh[i]={};
        }
        if ( i == 9){
            neigh[i]={};
        }
    }

    ans = 0;
    curr = 0;
    back_tracking(0, "corner" );
    ans += curr*4;
    curr = 0;
    back_tracking(0, "middle");
    ans += curr*4;
    curr = 0;
    back_tracking(0, "middle");
    ans += curr;
    cout << ans << "\n";
}