#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll inf=1e18+7;

struct A
{
    int u; ll s,w;
};

int shop[25],sz;
vector<A> adj[200500];
pll points[1000500],strip[1000500];
queue<A> qu;

ll calDist(pll a, pll b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

bool asy(pll a, pll b){
    return a.second<b.second;
}

ll play(int l, int r){
    ll mn=inf;
    if(r-l+1<=3){
        for(int i=l;i<=r;i++){
            for(int j=i+1;j<=r;j++){
                mn=min(mn,calDist(points[i],points[j]));
            }
        }
        return mn;
    }
    int mid=(l+r)>>1,idx=0;
    mn=min(play(l,mid), play(mid+1,r));
    ll d=ceil(sqrt(mn));
    for(int i=l;i<=r;i++){
        if(abs(points[mid].first-points[i].first)<d) strip[idx++]=points[i];
    }
    sort(strip,strip+idx,asy);
    for(int i=0;i<idx;i++){
        for(int j=i+1;j<idx  && strip[j].second-strip[i].second<d;j++){
            if(calDist(strip[i], strip[j])<mn) mn=calDist(strip[i], strip[j]);
        }
    }
    return mn;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n,m,l;
    cin >> n >> m >> l;
    for(int i=1;i<=l;i++) cin >> shop[i];
    for(int i=1;i<=m;i++){
        int u,v,s,w;
        cin >> u >> v >> s >> w;
        adj[u].push_back({v,s,w});
    }
    qu.push({1,0,0});
    while(!qu.empty()){
        A t=qu.front();
        qu.pop();
        if(t.u==n){
            points[sz++]={t.s,t.w};
            continue;
        }
        for(auto e:adj[t.u]){
            if(e.s==1) qu.push({e.u,t.s+e.w,t.w});
            else qu.push({e.u,t.s,t.w+e.w});
        }
    }
    sort(points,points+sz);
    cout << play(0,sz-1);
    return 0;
}