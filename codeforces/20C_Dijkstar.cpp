#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;

struct A
{
    int u; ll w;
    bool operator<(const A &o)const{
        return w>o.w;
    }
};

ll dist[100500];
priority_queue<A> pq;
vector<int> ans;
vector<A> adj[100500];
int path[100500];

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    memset(dist,0x3f,sizeof(dist));
    pq.push({1,0});
    dist[1]=0;
    while(!pq.empty()){
        int u=pq.top().u;
        ll w=pq.top().w;
        pq.pop();
        if(dist[u]<w) continue;
        for(auto e:adj[u]){
            if(dist[e.u]<=w+e.w) continue;
            pq.push({e.u,w+e.w});
            dist[e.u]=w+e.w;
            path[e.u]=u;
        }
    }
    if(!path[n]) cout << "-1";
    else {
        ans.push_back(n);
        ans.push_back(path[n]);
        int idx=path[n];
        while(path[idx]){
            ans.push_back(path[idx]);
            idx=path[idx];
        }
        reverse(ans.begin(),ans.end());
        for(auto e:ans) cout << e << ' ';
    }
    return 0;
}