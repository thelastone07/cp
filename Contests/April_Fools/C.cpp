#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    int count = 0;
    int m = 0;
    while(m < t) {
        int ans=1;
        if(m % 2 == 0){
            count = 3;
            while(count--){
                int n;
                cin >> n;
                ans *= n;
            }
        }else{
            count = 2;
            while(count--){
                int n;
                cin >> n;
                ans *= n;
            }
        }
        cout << ans << "\n";
        m++;
    }
    return 0;
}