#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    int result = ((a < b) ? a : b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }
 
    // Return gcd of a and b
    return result;
}

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    int m = 1;
    int hcf = gcd(a,b);

    //increase the length of the leg to hcf
    ans += hcf - m;
    m = hcf;

    int small = a < b ? a : b;
    int large = a < b ? b : a;

    ans += small/m;

    //find a product of large whose sum is minimum

    int num = floor(sqrt(large));
    
    if (num < m) num = m;
    else {
        while ( large % num != 0) num++;
    }
    int min_ans = (num - m) + large/num;

    while(1) {
        do{
            num++;
        }while( large % num != 0 && num < large);

        int t_ans = (num - m) + large/num;

        if (t_ans > min_ans) break;
        else min_ans = t_ans;
    }

    cout << min_ans +  ans << '\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}