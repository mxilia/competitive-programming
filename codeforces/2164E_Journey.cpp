#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

struct E
{
    int u,w,idx;
};

vector<E> adj[1000005];

void solve(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w,i});
        adj[v].push_back({u,w,i});
    }
    
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}