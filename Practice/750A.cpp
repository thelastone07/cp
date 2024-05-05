#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;


int new_year(int n, int k){
    int T = 240;
    T = T-k; //time left
    int count =0;
    for(int i=1;i<=n;i++){
        if(T<=0 || T<i*5)break;
        else{
            T=T-5*i;
            
            count++;
        }
    }
    return count;
}

int main(){

    int n, k;
    
    cin>>n>>k;
    cout<<new_year(n, k);
    
    return 0;
}