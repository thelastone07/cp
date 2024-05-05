#include<bits/stdc++.h>
using namespace std;
#define int long long int



void solve(){

    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        if(s[i]=='+')
        v[i]=1;
    }

    for(int i=1;i<n;i++)
    v[i]+=v[i-1];

    int ans=0;
    for(int i=0;i<n;i++)
    {
        int temp=0,curr=0;
        for(int j=i;j<n;j++)
        {
            if(s[j]=='-')
            curr++;
            int rg=curr;
            if(s[j]=='+')
            curr=0;
            if(rg!=0 && rg%2==0)
            temp++;
            int sz=j-i+1;
            int plus=v[j];
            if((i-1)>=0)
            plus-=v[i-1];
            int minus=sz-plus;
            int mxplus=plus+(temp/2);
            if(minus==plus)
            {
                ans++;
                cout << s.substr(i, j-i+1) <<'\n';
                continue;
            }
            if(minus>plus)
            {
                if((minus-plus)%3==0)
                {
                    int dg=(minus-plus)/3;
                    if(temp>=dg && (plus+dg==minus-2*dg)){
                    ans++;
                    cout << s.substr(i, j-i+1) <<'\n';

                    }
                    
                }
            }
        }

    }
    cout<<ans<<"\n";
}



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    solve();
}