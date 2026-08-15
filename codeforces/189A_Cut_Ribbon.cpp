#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;

int dp[4005],l[3];

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n >> l[0] >> l[1] >> l[2];
    for(int i=1;i<=n;i++){
        for(int j=0;j<3;j++){
            if((i-l[j]>0 && dp[i-l[j]]>0) || (i-l[j]==0)) dp[i]=max(dp[i],dp[i-l[j]]+1);
        }
    }
    cout << dp[n];
    return 0;
}

