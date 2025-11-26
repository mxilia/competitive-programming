#include <bits/stdc++.h>
#define newline cout << "\n";
#define f first
#define s second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define int long long

int a[200005];

void solve(){
    int n, cnt = 0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(i>1 && i<n) a[i]=max(a[i],0ll); 
    }
    if(a[1]==-1 && a[n]!=-1){
        int sum=0;
        for(int i=2;i<=n;i++) sum+=a[i]-max(0ll,a[i-1]);
        a[1]=max(0ll,sum);
    }
    if(a[n]==-1){
        int sum=0;
        if(a[1]==-1) a[1]=0;
        for(int i=2;i<=n-1;i++) sum+=a[i]-a[i-1];
        a[n]=max(0ll,a[n-1]-sum);
    }
    int ans=0;
    for(int i=2;i<=n;i++) ans+=a[i]-a[i-1];
    cout << abs(ans); newline
    for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
