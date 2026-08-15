#include <bits/stdc++.h>
#define newline cout << "\n";
#define f first
#define s second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define int long long

int a[200005],qs[200005];

void solve(){
    int n,mx=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        qs[i]=a[i]+qs[i-1];
    }
    int l=-1, mxl=-1;
    for(int r=1;r<=n;r++){
        if(mxl<qs[r-1]-r*r+r){
            l=r;
            mxl=qs[l-1]-l*l+l;
        }
        mx=max(mx, qs[n]-qs[r]+r*r+r+mxl);
    }
    cout << mx << "\n";
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
4
3
2 5 1
2
4 4
4
1 3 2 1
5
3 2 0 9 10
*/