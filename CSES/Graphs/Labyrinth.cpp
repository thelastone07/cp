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

#define nl "\n"
#define mp make_pair
#define pb push_back
#define ins insert
#define f first
#define s second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
int n, m;
vector<vector<pi>> path;
vector<vector<bool>> vis;
int sx, sy, ex, ey;

vector<pair<int,int>> moves = {{-1,0}, {1,0}, {0,-1}, {0,1}};

bool isValid(int x, int y) {
    if ( x < 0 or x >= n or y < 0 or y >= m)
        return false;
    if (vis[x][y]) 
        return false;
    return true;
}

void bfs() {
    queue<pi> q;
    q.push({sx,sy});

    while( !q.empty()) {
        int cx = q.front().f;
        int cy = q.front().s;
        q.pop();

        for ( auto move : moves) {
            int mvx = move.f;
            int mvy = move.s;
            int x = cx + mvx;
            int y = cy + mvy;
            if (isValid(x, y)) {
                q.push({ x, y});
                vis[x][y] = 1;
                path[x][y] = {mvx, mvy};
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    path.resize(n);
    vis.resize(n);

    for(int i = 0; i < n ; i++) {
        path[i].resize(m);
        vis[i].resize(m);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            path[i][j] = {-1,-1};
            char c;
            cin >> c;
            if ( c == '#')
                vis[i][j] = true;
            if (c == 'A') {
                sx = i;
                sy = j;
            }
            if ( c == 'B') {
                ex = i;
                ey = j;
            }
        }
    }
    bfs();

    if (!vis[ex][ey]) {
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;

    vector<pi> ans;
    pi end = {ex, ey};
    // ans.pb(end);
    // cout << ans.back().f << ans.back().s;
    while (end.f != sx or end.s != sy) {
        ans.pb(path[end.f][end.s]);
        end.first -= ans.back().first;
		end.second -= ans.back().second;
    }
    reverse(all(ans));
    cout << ans.size()  << nl;

    for(auto c: ans)
	{
		if(c.first == 1 and c.second ==0)
		{
			cout << 'D';
		}
		else if(c.first == -1 and c.second ==0)
		{
			cout << 'U';
		}
		else if(c.first == 0 and c.second == 1)
		{
			cout << 'R';
		}
		else if(c.first == 0 and c.second == -1)
		{
			cout << 'L';
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