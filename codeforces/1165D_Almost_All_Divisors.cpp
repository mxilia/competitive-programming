#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;
const int inf=1e9+7;

int d[1005],ans;

void solve(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> d[i];
    sort(d,d+n);
    ans=d[0]*d[n-1];
    for(int i=1;i<=n/2;i++){
        if(d[i]*d[n-1-i]!=ans){
            cout << "-1"; newline
            return;
        }
    }
    cout << ans;
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}