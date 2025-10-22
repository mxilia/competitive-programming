#include <bits/stdc++.h>
#define newline cout << "\n";
#define u first
#define w second
using namespace std;
using pii=pair<int,int>;

vector<pii> adj[105];
int dp[105][105],sum[105][105],c[105],sumtree[105],t[105];
int n,k,all;

void dfs(int u,int dist=0,int p=-1){
    sumtree[u]+=t[u];
    c[u]++;
    all+=t[u]*dist;
    for(auto e:adj[u]){
        if(e.u==p) continue;
        dfs(e.u,dist+e.w,u);
        c[u]+=c[e.u];
        sumtree[u]+=sumtree[e.u];
        for(int i=c[u];i>=0;i--){
            if(dp[e.u][i]!=-1 && dp[e.u][i]>dp[u][i]){
                dp[u][i]=dp[e.u][i];
                sum[u][i]=sum[e.u][i];
            }
            for(int j=0;j<=c[e.u];j++){
                if(i-j<0 || dp[u][i-j]==-1 || dp[e.u][j]==-1 || dp[u][i]>=dp[u][i-j]+dp[e.u][j]) continue;
                dp[u][i]=dp[u][i-j]+dp[e.u][j];
                sum[u][i]=sum[u][i-j]+sum[e.u][j];
            }
        }
        for(int i=1;i<=c[u];i++){
            if(dp[u][i-1]!=-1 && dp[u][i]>=dp[u][i-1]) continue;
            dp[u][i]=dp[u][i-1];
            sum[u][i]=sum[u][i-1];
        }
    }
    for(int i=c[u];i>=1;i--){
        if(dp[u][i-1]!=-1 && dp[u][i]>=dp[u][i-1]+(sumtree[u]-sum[u][i-1])*dist) continue;
        dp[u][i]=dp[u][i-1]+(sumtree[u]-sum[u][i-1])*dist;
        sum[u][i]=sum[u][i-1]+t[u];
    }
    for(int i=1;i<=c[u];i++){
        if(dp[u][i-1]!=-1 && dp[u][i]>=dp[u][i-1]) continue;
        dp[u][i]=dp[u][i-1];
        sum[u][i]=sum[u][i-1];
    }
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        int w,v,d;
        cin >> w >> v >> d;
        ::t[i]=w;
        adj[v].push_back({i,d});
        adj[i].push_back({v,d});
    }
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<=n;i++) dp[i][0]=0;
    dfs(0);
    cout << all-dp[0][k];
    return 0;
}