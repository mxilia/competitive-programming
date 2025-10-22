#include <bits/stdc++.h>
#define newline cout << '\n';
using namespace std;

struct A
{
    int w,l;
};

A a[20050];
int dp[20500],l[20500],r[20500],ans;
vector<int> idx[20500];

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].w >> a[i].l;
        dp[i]=2e9;
    }
    for(int i=1;i<=n;i++){
        int mx=0;
        for(int j=i;j>=1;j--){
            if(a[i].l>=dp[j-1]){
                mx=max(mx,j);
                dp[j]=min(dp[j],dp[j-1]+a[i].w);
            }
        }
        l[i]=mx;
    }
    memset(dp,0,sizeof(dp));
    dp[0]=2e9;
    for(int i=n;i>=1;i--){
        int mx=0;
        for(int j=(n-i+1);j>=1;j--){
            if(dp[j-1]>=a[i].w){
                mx=max(mx,j);
                dp[j]=max(dp[j],min(a[i].l,dp[j-1]-a[i].w));
            }
        }
        r[i]=max(mx,r[i+1]);
    }
    for(int i=1;i<n;i++){
        int cur=l[i]+r[i+1];
        idx[cur].push_back(i);
        ans=max(ans,cur);
    }
    cout << ans; newline
    for(auto e:idx[ans]) cout << e << " ";
    return 0;
}
/*
5
2 15
4 5
2 6
7 11
8 10
*/
