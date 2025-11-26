#include <bits/stdc++.h>
#define newline cout << "\n";
#define f first
#define s second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define int long long

int a[200005],mxr[200005],mnl[200005],flag[200005];
vector<pii> edge;

void solve(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    mxr[n]=a[n];
    mxr[n+1]=0;
    for(int i=n-1;i>=1;i--) mxr[i]=max(a[i],mxr[i+1]);
    mnl[1]=a[1];
    for(int i=2;i<=n;i++) mnl[i]=min(a[i],mnl[i-1]);
    bool ch = true;
    for(int i=1;i<=n;i++){
        if(mnl[i-1]>a[i] && mnl[i-1]>mxr[i+1]) ch = false;
    }
    if(ch) cout << "Yes";
    else cout << "No";
    newline
    if(!ch) return;
    for(int i=2;i<=n;i++){
        if(flag[a[i]]) continue;
        if(mnl[i-1]<a[i]){
            edge.push_back({mnl[i-1],a[i]});
        }
        else {
            if(!flag[mxr[i+1]]){
                edge.push_back({mnl[i-1],mxr[i+1]});
                flag[mxr[i+1]]=1;
            }
            edge.push_back({a[i],mxr[i+1]});
        }
    }
    for(auto &e:edge) cout << e.first << " " << e.second << "\n";
    memset(flag,0,sizeof(flag));
    edge.clear();
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
6
2 4 6 1 3 5
*/