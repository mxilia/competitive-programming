#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using pii=pair<int,int>;
using ll=long long;
const ll inf=1e18+7;
 
struct A
{
    int u; ll w; int k;
    bool operator<(const A &o)const{
        return w>o.w;
    }
};
 
struct E
{
    int u,k;
};
 
 
ll dist[100005],cnt;
priority_queue<A> pq;
vector<A> adj[100005];
vector<E> dag[100005];
 
void dijk(ll arr[]){
    while(!pq.empty()){
        int u=pq.top().u;
        ll w=pq.top().w;
        pq.pop();
        if(w>dist[u]) continue;
        for(auto e:adj[u]){
            if(arr[e.u]>w+e.w){
                pq.push({e.u,w+e.w});
                arr[e.u]=w+e.w;
                dag[e.u].clear();
                dag[e.u].push_back({u,e.k});
            }
            else if(arr[e.u]==w+e.w) dag[e.u].push_back({u,e.k});
        }
    }
}
 
void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int u,v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w,0});
        adj[v].push_back({u,w,0});
    }
    for(int i=1;i<=k;i++){
        int s; ll y;
        cin >> s >> y;
        adj[1].push_back({s,y,1});
        adj[s].push_back({1,y,1});
    }
    memset(dist,0x3f,sizeof(dist));
    pq.push({1,0});
    dist[1]=0;
    dijk(dist);
    cnt=0;
    for(int i=1;i<=n;i++){
        int b=0;
        for(auto e:dag[i]){
            if(e.k) b|=1;
            else b|=2;
        }
        if(b==1) cnt++;
    }
    cout << k-cnt;
    return;
}
 
signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
    return 0;
}