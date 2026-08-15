#include <bits/stdc++.h>
#define newline cout << "\n";
#define f first
#define s second
using namespace std;
const int inf=1e9+7;
using pii=pair<int,int>;

vector<int> adj[500500];
vector<int> lv[500500];
vector<pii> leaves;
queue<int> qu;
int dp[500500],depth[500500],mx;

int dfs(int u,int cnt,int p=-1){
    mx=max(mx,cnt);
    lv[cnt].push_back(u);
    dp[u]=1;
    depth[u]=cnt;
    for(auto v:adj[u]){
        if(v==p) continue;
        dp[u]+=dfs(v,cnt+1,u);
        depth[u]=max(depth[u],depth[v]);
    }
    if(dp[u]==1) leaves.push_back({cnt,u});
    return dp[u];
}

int bfs(int u,int d){
    int sum=0;
    if(depth[u]==d){
        qu.push(u);
        depth[u]=-1;
        sum++;
    }
    while(!qu.empty()){
        int u=qu.front();
        qu.pop();
        for(auto v:adj[u]){
            if(depth[v]==d){
                qu.push(v);
                depth[v]=-1;
                sum++;
            }
        }
    }
    return sum;
}

void solve(){
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    mx=0;
    dfs(1,1);
    int mn=inf,ptr=0,sum=0;
    sort(leaves.begin(),leaves.end());
    for(int i=1;i<=mx;i++){
        while(ptr<leaves.size() && leaves[ptr].f<i){
            sum+=bfs(leaves[ptr].s,leaves[ptr].f);
            ptr++;
        }
        int cur_sum=0;
        for(auto e:lv[i]) cur_sum+=dp[e]-1;
        mn=min(mn,sum+cur_sum);
    }
    cout << mn << '\n';
    leaves.clear();
    for(int i=1;i<=n;i++) adj[i].clear(), lv[i].clear();
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

/*
1
9
5 1
2 7
3 1
2 1
8 7
8 4
1 9
3 6
--
4
*/