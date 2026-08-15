#include <bits/stdc++.h>
#define newline cout << '\n';
using namespace std;

int dp[1<<20],arr[1<<20];

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i=0;i<(1<<n);i++){
        int bit=0;
        string s; cin >> s;
        for(int j=0;j<n;j++){
            bit|=(s[j]-'0')<<(n-j-1);
        }
        cin >> arr[bit];
    }
    for(int i=1;i<(1<<n);i++){
        int mx=-1e9;
        for(int j=1;j<(1<<n);j<<=1){
            if(i&j) mx=max(mx,arr[i]+dp[i^j]);
        }
        for(int j=3;j<(1<<n);j<<=1){
            if((i&j)==j) mx=max(mx,arr[i]+dp[i^j]);
        }
        dp[i]=mx;
    }
    while(q--){
        int bit=0;
        string s; cin >> s;
        for(int j=0;j<n;j++){
            bit|=(s[j]-'0')<<(n-j-1);
        }
        cout << dp[bit]; newline
    }
    return 0;
}
/*
10 3 1 10
10 20 30 40 50 60 70 80 90 100
*/
