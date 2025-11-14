#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

void solve(){
    int n,x,mn=INT_MAX,mx=INT_MIN;
    cin >> n;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        mx=max(mx,z);
        mn=min(mn,z);
    }
    cin >> x;
    if(mn<=x && x<=mx) cout << "YES";
    else cout << "NO";
    newline
    return;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}