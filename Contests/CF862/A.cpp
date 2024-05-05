#include<bits/stdc++.h>

using namespace std;

void zero(){
    int n;
    cin >> n;

    int a[n];
    int forward = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        forward = forward^a[i];
    }
    if (n % 2 == 0){
        if(forward == 0) cout << 0 << "\n";
        else cout << -1 << "\n";
    }
    else {
        cout << forward << "\n";
    }

     
}

signed main() {
    ios :: sync_with_stdio (false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while(t--){
        zero();
    }

    return 0;
}