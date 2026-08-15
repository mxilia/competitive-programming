#include <bits/stdc++.h>
#define newline cout << "\n";
#define int long long
using namespace std;
using pii=pair<int,int>;

int a[3][200005],lmn[200005],lmx[200005],rmn[200005],rmx[200005],pmx[200005];
vector<pii> p;

void solve(){
    int n;
    cin >> n;
    for(int j=1;j<=n;j++){
        cin >> a[1][j];
        if(j==1){
            lmn[j]=a[1][j];
            lmx[j]=a[1][j];
        }
        else {
            lmn[j]=min(a[1][j],lmn[j-1]);
            lmx[j]=max(a[1][j],lmx[j-1]);
        }
    }
    for(int j=1;j<=n;j++) cin >> a[2][j];
    for(int j=n;j>=1;j--){
        if(j==n){
            rmn[j]=a[2][j];
            rmx[j]=a[2][j];
        }
        else {
            rmn[j]=min(a[2][j],rmn[j+1]);
            rmx[j]=max(a[2][j],rmx[j+1]);
        }
    }
    for(int i=1;i<=n;i++){
        int mn=min(rmn[i],lmn[i]);
        int mx=max(rmx[i],lmx[i]);
        p.push_back({mx,mn});
    }
    sort(p.begin(),p.end(), greater<pii>());
    int prev=2*n+1, ans=0;
    pmx[n-1]=p[n-1].second;
    for(int i=n-2;i>=0;i--) pmx[i]=max(p[i].second,pmx[i+1]);
    for(int i=0;i<n;i++){
        int mx = p[i].first;
        if(mx!=prev){
            ans+=(prev-mx)*pmx[i];
            prev=mx;
        }
    }
    cout << ans; newline
    p.clear();
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

/*
1
2
1 3
3 1
*/