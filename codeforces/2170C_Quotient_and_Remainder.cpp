#include <bits/stdc++.h>
#define newline cout << "\n";
#define f first
#define s second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define int long long

int q[200005],r[200005];

void solve(){
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> q[i];
    for(int i=1;i<=n;i++) cin >> r[i];
    sort(q+1, q+n+1, greater<int>());
    sort(r+1, r+n+1); // y >= r+1
    int cr = 1, ans = 0;
    for(int i=1;i<=n;i++){
        if(q[i]*(r[cr]+1)+r[cr]<=k){
            cr++;
        }
    }
    cout << cr-1; newline
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