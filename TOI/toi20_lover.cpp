#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;

int dp[10050],dp1[10050],dp2[10050],inf;

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n,v,w;
    cin >> n >> v >> w;
    for(int i=1;i<=n;i++){
        int z;
        cin >> z;
        if(z%2){
            dp1[i]=z+dp1[i-1];
            dp2[i]=dp2[i-1];
        }
        else {
            dp1[i]=dp1[i-1];
            dp2[i]=z+dp2[i-1];
        }
    }
    memset(dp,0x3f,sizeof(dp));
    inf=dp[0];
    dp[0]=0;
    for(int i=2;i<=n;i+=2){
        for(int j=i-2;j>=0;j-=2){
            int vp=dp1[(i+j)/2]-dp1[j];
            int wp=dp2[i]-dp2[(i+j)/2];
            if(vp<=v && wp<=w) dp[i]=min(dp[i],dp[j]+1);
        }
    }
    if(dp[n]!=inf) cout << dp[n];
    else cout << "-1";
    return 0;
}
