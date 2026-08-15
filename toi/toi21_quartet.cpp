#include <bits/stdc++.h>
#define newline cout << '\n';
using namespace std;
using ll = long long;
const int md = 1e9+7;

vector<int> adj[200005];
ll dp[200005],qs[200005][6];
int n,m;
ll ans;

int dfs(int u, int p=-1){
    if(u<=n) dp[u]=1;
    vector<int> vec;
    for(auto &e:adj[u]){
        if(e==p) continue;
        int val = dfs(e,u);
        dp[u]+=val;
        if(u>n) vec.emplace_back(val);
    }
    vec.emplace_back(n-dp[u]);
    if(vec.size()>=4){
        int sz = vec.size();
        for(int i=1;i<=sz;i++) qs[i][1]=qs[i-1][1]+vec[i-1];
        for(int j=2;j<=4;j++){
            for(int i=1;i<=sz;i++){
                qs[i][j]=qs[i-1][j]+(qs[sz][j-1]-qs[i][j-1])*vec[i-1];
                if(j==4) qs[i][j]=qs[i][j]%md;
            }
        }
        ans=(ans+qs[sz][4])%md;
    }
    return dp[u];
}

void solve(){
    cin >> n >> m;
    for(int i=0;i<n+m-1;i++){
        int u,v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(n+1);
    cout << ans;
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t(1);
    // cin >> t;
    while(t--) solve();
    return 0;
}