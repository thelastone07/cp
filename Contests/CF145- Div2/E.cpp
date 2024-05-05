#include<bits/stdc++.h>

using namespace std;

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    
    int V[n];
    for(int i = 0; i < n; i++){
        cin >> V[i];
    }

    cout << "input successful";

    vector<vector<vector<int>>> dp(a+1,vector<vector<int>>(b+1, vector<int>(n,-1)));

    for( int C = 0; C <= a; C++){
        for ( int D = 0; D <= b; D++){
            int c = C;
            int d = D;
            // cout << "entered outer loop";
            for( int i = 0 ; i < n ; i++){
                // cout << "checking first condition";
                if (dp[c][d][i] != -1){
                    d = (c + d) - dp[c][d][i];
                    c = dp[c][d][i];
                }
                else{
                    // cout << "checking second condition";
                    if(V[i] == 0){
                        dp[c][d][i] = c;
                    }
                    else if (V[i] > 0)
                    {
                        int t = min({c, V[i], b-d});
                        c = c - t;
                        d = d + t;
                        dp[c][d][i] = c;
                    }
                    else{
                        int t = min({d, -V[i], c-a});
                        c = c + t;
                        d = d - t;
                        dp[c][d][i] = c;
                    }
                }             
            }
            cout << c << " ";   
        }
        cout << "\n";
    }
    return 0;
}


