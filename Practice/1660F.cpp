#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    
    vector<int>pos(n);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='+')
        pos[i]=1;
    }

    for(int i=1;i<n;i++)
    pos[i]+=pos[i-1];

    //creating substrings
    int ans = 0;
    for (int i = 0; i < n; i++) {

        // cout << i << '\n';
        int nneg = 0, curr = 0;

        for (int j = i; j < n; j++) {
            int plus, minus;
            
            if (i > 0) plus = pos[j] - pos[i-1];
            else plus = pos[j] ;
            minus = (j - i + 1) - plus;

            if ( s[j] == '-') curr++;
            if ( curr % 2 == 0 && curr != 0) {
                nneg++;
            }
            if ( s[j] == '+') curr = 0;

            // if (i == 3 && j == i + 1) {
            //     cout << "plus"  << plus;
            //     cout << "minus" << minus;
            // }

            if ( plus == minus) {
                ans += 1;
                // cout << s.substr(i, j-i+1) <<'\n';
                continue;
            }
            else if ( plus > minus ) continue;
            else 
            { if ( (minus - plus) % 3 == 0) {
                int pairs = (minus - plus) / 3;
                if ( nneg >= pairs && (plus + pairs == minus - 2 * pairs)){
                    ans++;
                    // cout << s.substr(i, j-i+1) <<'\n';
                    }  
                }
            }
        }
    }

    cout << ans << '\n';    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}

