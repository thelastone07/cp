#include<bits/stdc++.h>
#define val 1e12
#define ll long long

using namespace std;


ll find_min(string s, int pos){
    int ones = count(s.begin(), s.end(), '1'); // right of the character we are in
    int zeros = 0; // left of the character we are in including that character
    ll ans = 1e18;
    
    if (s.size() == 1) ans = 0;

    for(int i = 0; i<s.length()-1; i++){
        ones -= s[i] == '1'; 
        zeros += s[i] == '0';
        int k = zeros + ones + ( s[i] == '1' ) + (s[i+1] == '0');
        ll cur = (s.size() - k) * (val + 1);
        if(s[i]>s[i+1]){
            cur += val;
        }
        ans = min(ans, cur);
    }

    return ans;

}

void binary() {
    string s;
    cin >> s;
    cout << find_min(s,0) << "\n";
}

signed main() {
    ios :: sync_with_stdio( false );
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        binary();
    }

    return 0;
}