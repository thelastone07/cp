#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

int find_zeros(int arr[], int n){
    int count =0;
    for(int i=0;i<n;i++)if(arr[i]==0)count++;
    return count;
}

int mex_master(int arr[], int n){
    int zeros = find_zeros(arr,n);
   
    
    if(zeros<=(n+1)/2){
       return 0;
    }
    else{
        int max = *max_element(arr,arr+n);
        if(max!=1)return 1;
        else return 2;
    }
}

int main(){
    int t;
    cin>>t;
    int ans[t];
    while(t){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        ans[t-1]=mex_master(a,n);
        t--;
    }
    for(int i=sizeof(ans)/sizeof(int)-1;i>=0;i--)cout<<ans[i]<<"\n";

    return 0;
}