#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;

int deg[2005],mx,cnt;
vector<int> adj[2005];

void dfs(int u){
    mx=max(mx,cnt);
    for(auto e:adj[u]){
        cnt++;
        dfs(e);
        cnt--;
    }
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int p; cin >> p;
        if(p==-1) continue;
        deg[i]++;
        adj[p].push_back(i);
    }
    for(int i=1;i<=n;i++) if(!deg[i]) dfs(i);
    cout << mx+1;
    return 0;
}