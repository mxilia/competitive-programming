#include <bits/stdc++.h>
#define newline cout << "\n";
#define f first
#define s second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define int long long

int b[200005], parent[200005];
pii p[200005];

int fSet(int n){
    if(parent[n]==n) return n;
    return parent[n]=fSet(parent[n]);
}
 
struct A
{
    int i;
    bool operator<(const A &o)const{
        return b[fSet(i)]>b[fSet(o.i)];
    }
};
 
priority_queue<A> pq;

void solve(){
    int n,ans=0;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++){
        parent[i]=i;
        pq.push({i});
        if(i!=1) p[i].first = i-1;
        if(i!=n) p[i].second = i+1;
    }
    p[1].first = n, p[n].second = 1;
    while(pq.size()>1){
        int i=pq.top().i;
        pq.pop();
        int pl=fSet(p[i].first), pr=fSet(p[i].second);
        if(b[pl]<b[pr]){
            ans+=b[pl];
            parent[i]=pl;
            p[pl].second = p[i].second;
        }
        else {
            ans+=b[pr];
            parent[i]=pr;
            p[pr].first = p[i].first;
        }
    }
    cout << ans; newline
    pq.pop();
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
4
1 1 3 2
*/