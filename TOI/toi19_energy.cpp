#include <bits/stdc++.h>
#define newline cout << "\n";
#define int long long
using namespace std;
const int mod=1e9+7;

int n,K,d;
int a[500],qs[500];
int dp[500][500][15],visited[500][500][15];

int play(int l,int r,int k){
    if(visited[l][r][k]) return dp[l][r][k];
    visited[l][r][k]=1;
    if(dp[l][r][k]) return dp[l][r][k];
    if(k==K) return dp[l][r][k]=1;
    int sum=0;
    for(int i=l;i<r;i++){
        int diff=abs((qs[r]-qs[i])-(qs[i]-qs[l-1]));
        if(diff<=d) sum=(sum+play(l,i,k+1)*play(i+1,r,k+1))%mod;
    }
    return dp[l][r][k]=sum;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> K >> d;
    for(int i=1;i<=n;i++) cin >> a[i],qs[i]=a[i]+qs[i-1];
    cout << play(1,n,1);
    return 0;
}
