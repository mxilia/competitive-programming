#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;

ll a[105];

void solve(){
    int n; ll h;
    cin >> n >> h;
    for(int i=0;i<n;i++) cin >> a[i];
    ll l=1,r=1e18;
    while(l<r){
        ll mid=((r-l)>>1)+l,sum=0;
        for(int i=0;i<n-1;i++) sum+=min(mid,a[i+1]-a[i]);
        sum+=mid;
        if(sum>=h) r=mid;
        else l=mid+1;
    }
    cout << l; newline
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}