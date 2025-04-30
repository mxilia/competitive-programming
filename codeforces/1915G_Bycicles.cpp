#include <bits/stdc++.h>
#define newline cout << "\n";
#define u first
#define w second
using namespace std;
using pii=pair<int,int>;
using ll=long long;
const ll inf=1e18+7;
 
struct A
{
    int u;
    ll w;
    int s;
    bool operator<(const A &o)const{
        return w>o.w;
    }
};
int bike[1005];
ll dist[1005][1005];
vector<pii> adj[1005];
priority_queue<A> pq;
 
void solve(){
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i=1;i<=n;i++) cin >> bike[i];
    for(int i=1;i<=n;i++) for(int j=1;j<=1000;j++) dist[i][j]=inf;
    pq.push({1,0,bike[1]});
    dist[1][bike[1]]=0;
    while(!pq.empty()){
        int u=pq.top().u;
        ll w=pq.top().w;
        int s=pq.top().s;
        pq.pop();
        if(bike[u]!=s && dist[u][bike[u]]>w){
            pq.push({u,w,bike[u]});
            dist[u][bike[u]]=w;
        }
        for(auto e:adj[u]){
            if(dist[e.u][s]<=w+e.w*s) continue;
            pq.push({e.u,w+e.w*s,s});
            dist[e.u][s]=w+e.w*s;
        }
    }
    ll ans=inf;
    for(int i=1;i<=1000;i++) ans=min(ans,dist[n][i]);
    cout << ans; newline
    for(int i=1;i<=n;i++) adj[i].clear();
    return;
}
 
signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}