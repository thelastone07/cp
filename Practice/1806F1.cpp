#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;


int gcd_sum(int *a,int n, int m, int k){
    sort(a, a+n);
    return 0;
}

int main(){
    int t, n, m, k;
    cin>>t;
    int ans[t];
    while(t>0){
        cin>>n>>m>>k;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        ans[t-1]=gcd_sum(a,n,m,k);
        t--;
    }
    for(int i=sizeof(ans)/sizeof(int)-1;i>=0;i--)
            cout<<ans[i]<<"\n";

    return 0;
}