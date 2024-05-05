// #include<bits/stdc++.h>

// using namespace std;

// vector<vector<int>> adj;
// vector<bool> vis;
// bool possible = false;
// vector<int> par;
// int s,e;

// bool dfs(int v, int p) {
//     par[v] = p;
//     vis[v] = true;
//     // cout << "Visiting" << v+1 << " " << p+1 << '\n';
//     for (auto &u : adj[v]) {
//         if (!vis[u]) {
//             return dfs(u,v);
//         } else {
//             if (u != p ) {
//                 s = u;
//                 e = v;
//                return true;
//             }
//         }
//     }
//     return false;
// }

// void solve() {
//     int  n ,m;
//     cin >> n >> m;

//     adj.resize(n+1);
//     vis.resize(n+1,false);
//     par.resize(n+1);

//     for (int i = 1; i <= m; i++) {
//         int a,b;
//         cin >> a >> b;

//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }

//     for (int i = 1; i <= n; i++) {
//         if (!vis[i]) {
//             if (dfs(i,0)) {
//                 int tv = e;
//                 vector<int> ans;
//                 ans.push_back(e);
//                 while(tv != s) {
//                     ans.push_back(par[tv]);
//                     tv = par[tv];
//                 }
//                 ans.push_back(e);
//                 cout << ans.size() << endl;
//                 for(auto c: ans) {
//                     cout << c  << " ";
//                 }
//                 return;
//             }
//         }
//     }

//     cout << "IMPOSSIBLE\n";

// }

// signed main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     solve();

//     return 0;
// }


#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
 
int n, m;
int sv, ev;
vector<vector<int>> g;
vector<int> vis;
vector<int> parent;
 
 
bool dfs(int u, int p)
{
	vis[u] = true;
	parent[u] = p;
	for(auto v: g[u])
	{
		if(v == p) continue;
		if(vis[v]) 
		{
			sv = v; 
			ev = u; 
			return true;
		} 
		if(!vis[v]) 
			if(dfs(v,u)) 
				return true;
	}
	return false;
}
 
 
bool visit_all()
{
	for(int i = 1; i <= n; ++i)
	{
		if(!vis[i])
			if(dfs(i,-1)) return true;
	}
	return false;
}
 
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	g.resize(n+1);
	vis.resize(n+1);
	parent.resize(n+1);
	for(int i =0 ; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
 
	if(!visit_all())
	{
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
 
	int tv = ev;
	vector<int> ans;
	ans.push_back(ev);
	while(tv != sv)
	{
		ans.push_back(parent[tv]);
		tv = parent[tv];
	}
	ans.push_back(ev);
	cout << ans.size() << endl;
	for(auto c: ans)
	{
		cout << c << " ";
	}
 
}