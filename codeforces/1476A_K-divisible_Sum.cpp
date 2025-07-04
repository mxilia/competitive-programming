#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;

void solve(){
    ll n,k;
    cin >> n >> k;
    ll l=1,r=2e9;
    while(l<r){
        ll mid=(l+r)>>1;
        if(mid*k>=n) r=mid;
        else l=mid+1;
    }
    ll d=(l*k)/n;
    int m=(l*k)%n;
    if(m) cout << d+1;
    else cout << d;
    newline
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}