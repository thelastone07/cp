#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;

typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<double,double> pdd;
typedef vector<ll> vl;
typedef vector<int> vi;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define FOR(i,e) for(ll i = 0; i < e; i++)
#define FORd(i,s) for(ll i = s - 1; i >= 0; i--)
#define nl "\n"
#define sp " " 
#define mp make_pair
#define pb push_back
#define ins insert
#define f first
#define s second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
vector<vi> adj;
vector<bool> vis;

void dfs(int n) {
    if (vis[n])
        return ;
    vis[n] = true;
    for ( auto &x : adj[n])
        dfs(x);
            
}

void solve() {
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    vis.resize(n,false);

    FOR(i,m){
        int a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }

    vi ans;

    FOR(i,n) {
        if (!vis[i]){
            dfs(i);
            ans.pb(i+1);
        }
    }

    int roads = sz(ans) - 1;
    cout << roads << nl;
    if (roads ) {
        FOR(i, roads) {
            cout << ans[i] << sp << ans[i+1] << nl;
        }
    }
    
}

int main() {
   fast_cin();
   int t = 1;
//    cin >> t;
   while (t--) {
       solve();
   }
   return 0;
}