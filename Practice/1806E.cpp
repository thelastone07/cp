#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>

using namespace std;

ll f(int x, int y, ll a[],int p[], vector<vector<long>> &ans){
    if(x==0 && y==0)return 0;
    if(ans[x][y]!=0)return ans[x][y];
    else{
        ans[x][y]=ans[x][y]+a[x]*a[y]+f(p[x],p[y],a,p,ans); 
    }
    return ans[x][y];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n, q;
    cin>>n>>q;
    vector<vector<long>> ans(n+1,vector<long>(n+1,0));
    ll a[n+1];
    for(int i =1;i<=n;i++)cin>>a[i];
    int p[n+1];
    p[1]=0;
    for(int i=2;i<=n;i++)cin>>p[i];
    while(q){
        //perform queries
        int x, y;
        cin>>x>>y;
        f(x, y, a, p, ans);
        cout<<ans[x][y]<<"\n";
        q--;
    }
    return 0;
}