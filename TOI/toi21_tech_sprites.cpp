#include <bits/stdc++.h>
#define newline cout << '\n';
using namespace std;
const int inf=1e9+7;
using pii = pair<int,int>;

struct B
{
    pii t;
    int val;
    B(pii t={0,0}, int val=0):t(t),val(val){}
    bool operator<(const B &o)const{
        if(t==o.t) return val>o.val;
        return t<o.t;
    }

};
B vec[2000005];
queue<int> qu;
pii atr[1000005],mn,mx;
vector<pair<int,int>> edge;
bool flag[1000005];
int deg[1000005];

void solve(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int a,b;
        cin >> atr[i].first >> atr[i].second;
    }
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        edge.push_back({u,v});
        deg[u]++; deg[v]++;
        
    }
    vector<vector<int>> adj(n+5);
    for(int i=1;i<=n;i++) adj[i].reserve(deg[i]+5);
    for(auto &e:edge){
        adj[e.first].emplace_back(e.second);
        adj[e.second].emplace_back(e.first);
    }
    int pt=0;
    for(int i=1;i<=n;i++){
        mn={inf,inf};
        mx={-inf,-inf};
        if(!flag[i]){
            qu.push(i);
            flag[i]=true;
            while(!qu.empty()){
                int v=qu.front();
                mx=max(mx,atr[v]);
                mn=min(mn,atr[v]);
                qu.pop();
                for(auto e:adj[v]){
                    if(flag[e]) continue;
                    qu.push(e);
                    flag[e]=true;
                }
            } 
            vec[pt++]={mn,1};
            vec[pt++]={mx,-1};
        }
    }
    sort(vec,vec+pt);
    int cnt=0,ans=0;
    for(int i=0;i<pt;++i){
        if(cnt && vec[i].val==1) ans++;
        cnt+=vec[i].val;
    }
    cout << ans;
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
    return 0;
}