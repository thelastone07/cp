#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;



void points(){
    ll n;
    cin>>n;

    ll x = sqrt(n);
    while(x*x<n)x += 1;
    // while((x-1)*(x-1)>=n)x -= 1;
    x -= 1;
    cout<<x<<"\n";
     
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T){
        points();
        T--;
    }
    return 0;
}