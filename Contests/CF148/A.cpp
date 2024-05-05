#include<bits/stdc++.h>

using namespace std;

signed main () {
    ios :: sync_with_stdio (false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;
        set<char> uniq (s.begin(),s.end());
        if( uniq.size() > 2) cout << "YES\n";
        else{
            if(uniq.size() == 1) cout << "NO\n";
            else{
                if ( count(s.begin(),s.end(),*uniq.begin()) == 1 or count(s.begin(),s.end(),*uniq.rbegin()) == 1)
                    cout << "NO\n";
                else cout << "YES\n";
            }
        }
    }
}