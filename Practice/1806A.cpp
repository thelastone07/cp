#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

int walking_master(int a, int b, int c, int d){
    int y_steps = d-b;
    if(y_steps<0)return -1;
    int curr_x = a+y_steps;
    int x_steps = curr_x - c;
    if(x_steps>=0) return x_steps+y_steps;
    return -1;
}

int main(){
    int t;
    cin>>t;
    int ans[t];
    while(t){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        ans[t-1]=walking_master(a,b,c,d);
        t--;
    }
    for(int i=sizeof(ans)/sizeof(int)-1;i>=0;i--)
    cout<<ans[i]<<"\n";
    return 0;
}