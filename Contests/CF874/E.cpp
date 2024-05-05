#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    // cout<<"One";
    vector<set<int>> neigh(n+1);
    for(int i = 1; i <= n; i++) {
        neigh[i].insert(a[i]);
        neigh[a[i]].insert(i);
    } 
    // cout<<"Two";
    vector<int> d(n+1);
    for (int i = 1; i <= n; i++){
        d[i] = neigh[i].size();
    }
    // cout<<"Three";

    vector<bool> vis(n+1,false);    
    int bamboos = 0;
    int cycles = 0;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i] = true;
            vector<int> component = {i};
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for( int v: neigh[u]) {
                    if(!vis[v]){
                        vis[v] = true;
                        q.push(v);
                        component.push_back(v);
                    }
                }
            }
            bool bamboo = false;
            for(int j : component) {
                if(d[j] == 1) {
                    bamboo = true;
                    break;
                }

            }
            if(bamboo){
                bamboos++;
            } else {
                cycles ++;
            }
        }
    }    
    cout << cycles + min(bamboos,1) << " " << cycles + bamboos << endl ;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        solve();
    }
    return 0;
}
