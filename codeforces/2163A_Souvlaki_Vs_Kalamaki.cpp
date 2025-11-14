#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int a[105];

void solve(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        if(a[i]!=a[i+1] && i%2==0){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}