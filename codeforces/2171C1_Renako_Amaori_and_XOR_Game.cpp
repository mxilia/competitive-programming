#include <bits/stdc++.h>
#define newline cout << "\n";
#define f first
#define s second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define int long long

int a[200005], b[200005];

void solve(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    int at,bt;
    at=bt=0;
    for(int i=1;i<=n;i++){
        if(a[i]==b[i]){
            at+=a[i];
            bt+=a[i];
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]){
            if(i%2){
                if(at%2==0) at++;
                else bt++;
            }
            else {
                if(bt%2==0) bt++;
                else at++;
            }
        }
    }
    if(at%2==bt%2) cout << "Tie";
    else if(at%2) cout << "Ajisai";
    else cout << "Mai";
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