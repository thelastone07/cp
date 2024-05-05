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

vector<bool> vis, team;
bool possible;

void dfs(int u, int p = 0) {
    
    for (auto &v : adj[u]) {
        if (v != p) {
            team[v] = !team[u];
            vis[v] = true;
            dfs(v, u);
        } else {
            if (team[v] == team[u])
                possible = false;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;

    adj.resize(n);
    vis.resize(n,false);
    team.resize(n,false);

    for (int i = 1 ; i <= m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    possible = true;

    FOR(i, n) {
        if (!vis[i]) {
            vis[i] = true;
            dfs(i);
        }
    }

    if (!possible) {
        cout << "IMPOSSIBLE" << nl;
        return;
    } 
    FOR(i,n) {
        cout << (team[i] ? 1 : 2) << " ";
    }
    cout << nl;
    

}

int main() {
   fast_cin();
    solve();
   return 0;
}