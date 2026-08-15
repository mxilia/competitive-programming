#include <bits/stdc++.h>
#define newline cout << "\n";
#define f first
#define s second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define int long long

int b[200005],qs[200005];

void solve(){
    int n, sum=0;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> b[i];
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++) qs[i]=b[i]+qs[i-1];
    for(int i=1;i<=n;i++){
        if(b[i]==0) continue;
        if(qs[n]-(n-i+1)>=n-1){
            cout << n-i+1; newline
            break;
        }
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

/*
1
6
2 4 6 1 3 5
*/