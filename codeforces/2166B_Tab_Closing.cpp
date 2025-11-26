#include <bits/stdc++.h>
#define newline cout << "\n";
#define f first
#define s second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define int long long

void solve(){
    int a,b,n;
    cin >> a >> b >> n;
    if(a/n<=b && a==b) cout << "1";
    else if(a/n<b && a>=b) cout << "2";
    else if(a/n>=b && a>b) cout << "1";
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