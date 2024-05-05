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
#define mp make_pair
#define pb push_back
#define ins insert
#define f first
#define s second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

void solve() {
    int n;
    cin >> n;
    vi a(n),b(n);
    FOR(i,n) {
        cin >> a[i];
    }
    FOR(i,n) {
        //insert 0 p+1 th element where 0<=p <i
    }

}

int main() {
   fast_cin();
   int t = 1;
   cin >> t;
   while (t--) {
       solve();
   }
   return 0;
}