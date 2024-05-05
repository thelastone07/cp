#include<bits/stdc++.h>
#define ll long long

using namespace std;

int frequency(string s){
    int maxx=0;
    for(int i=0;i<4;i++){
        int max_c=0;
        for(int j=0;j<4;j++)
        if(s[i]==s[j])max_c++;
        maxx=max(maxx,max_c);
    }
    return maxx;

}

int garland(string s){
    //if aint character are same, return -1
    if(frequency(s)==1)return 4;
    if(frequency(s)==2)return 4;
    if(frequency(s)==3)return 6;
    return -1;
    
}

signed main(){
    cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    int ans[T];
    while(T){
        string s;
        cin>>s;
        ans[T-1]= garland(s);
        T--;
    }

    for(int i=sizeof(ans)/sizeof(int)-1;i>=0;i--)cout<<ans[i]<<"\n";
    return 0;

}