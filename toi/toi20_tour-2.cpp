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
pll points[1000500];
struct cmp
{
    bool operator()(const pll &l,const pll &r)const{
        if(l.second==r.second) return l.first<r.first;
        return l.second<r.second;
    }
};

set<pll, cmp> strip;
queue<A> qu;

ll calDist(pll a, pll b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
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
    int j=0;
    ll mn=inf;
    for(int i=0;i<sz;i++){
        ll d=ceil(sqrt(mn));
        while(i>j && points[i].first-points[j].first>=d){
            strip.erase(points[j]);
            j++;
        }
        auto itr1=strip.lower_bound({points[i].first,points[i].second-d});
        auto itr2=strip.upper_bound({points[i].first,points[i].second+d});
        for(auto itr=itr1;itr!=itr2;itr++) mn=min(mn,calDist(*itr,points[i]));
        strip.insert(points[i]);
    }
    cout << mn;
    return 0;
}