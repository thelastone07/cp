#include<bits/stdc++.h>

using namespace std;




void showstopper(){
    int n;
    cin >> n;
    int a[n], b[n];
    for ( int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for ( int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int a_max = *max_element( a, a+n);
    int b_max = *max_element( b, b+n);

    if( a_max == a[n-1] && b_max == b[n-1]) {
        cout << "yes\n";
    }
    else {
        for ( int i = n-2; i >= 0; i--){
            if ( a[n-1] < a[i]) {
                int temp = a[i];
                a[i] = b[i];
                b[i] = temp;
            }
        }
        for ( int i = n-2 ; i >= 0; i--){
            if( b[n-1] < b[i]) {
                int temp = a[i];
                a[i] = b[i];
                b[i] = temp;
            }
        }
        int a_max = *max_element( a, a+n);
        int b_max = *max_element( b, b+n);

        if( a_max == a[n-1] && b_max == b[n-1]) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while ( t-- ) {
        showstopper();
    }
    return 0;
}