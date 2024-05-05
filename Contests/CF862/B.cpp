#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;


    // for ( int i = 0; i < n; i++ ) {
    //     string newS = s[i]+ s.substr(0,i) + s.substr(i+1);
    //     for ( int j = 0; j < n; j++){
    //         if ( s[j] != newS[j] ) {
    //             if( s[j] - newS[j] > maxx){
    //                 maxx = s[j] - newS[j];
    //                 lex_s = newS;
    //             }
    //             break;
    //         }
    //     }
    // }
    // if( maxx == -1) lex_s = s;
    // cout << lex_s << "\n";

    set<char> a(s.begin(), s.end());
    // for ( auto a_ : a) cout << a_ << " ";
    int lex_i = s.rfind(*a.begin());
    
    cout << s[lex_i] + s.substr(0, lex_i) + s.substr( lex_i + 1) << "\n";

}

signed main() {
    ios :: sync_with_stdio (false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    
    while( t-- ) {
        solve();
    }
}