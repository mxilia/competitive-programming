#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    cout << n/2; newline
    while(n>3){
        cout << '2' << ' ';
        n-=2;
    }
    if(n) cout << n;
    return 0;
}