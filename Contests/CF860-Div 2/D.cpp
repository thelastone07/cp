#include<bits/stdc++.h>

using namespace std;

void print(int a[], int n){
    for(int i = 0; i < n; i++) cout << a[i] << " \n"[i == (n - 1)];
}



void shock() {
    int n;
    cin >> n;
    int a[n];
    int n_pos = 0, n_neg = 0, n_zero = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if( a[i] > 0) n_pos += 1;
        if( a[i] < 0) n_neg += 1;
        if ( a[i] == 0) n_zero += 1;
    }
    int pos[n_pos], neg[n_neg];
    int j = 0, k = 0;
    for ( int i = 0; i < n; i++){
        if ( a[i] > 0) pos[ j++] = a[i];
        if ( a[i] < 0) neg[ k++] = a[i];
    }
    int limit = *max_element(a, a+n) - *min_element(a, a+n);
    int b[n];
    fill(b, b+n ,0);
    int pos_sum = accumulate(pos, pos+ n_pos, 0);
    if( pos_sum < limit){ 
        cout << "YES\n";
        print(a, n);
        return;
    }
    int sum = 0;
    j = n_pos - 1;
    k = n_neg - 1;
    for ( int i = 0; i < n ; i++){
        if ( pos[j] + sum < limit ){    
             if( j >= 0) {
                b[i] = pos[j];
                sum += pos[j--];
            }  if(k >= 0) {
                b[ i] = pos[ k--];
            }   
        }
        else {
            if( k >= 0 ){
                b[ i] = neg[k--];
                sum = 0;
            }  if( j >= 0) {
                b[ i] = pos[ j--];
            }
        }
    }
    cout << "YES\n";
    print(b, n);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while ( t-- ){
        shock();
    }

    return 0;
}