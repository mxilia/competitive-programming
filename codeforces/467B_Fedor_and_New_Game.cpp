#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;

int a[1005],cnt[(1<<20)+50],ans;

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n,m,k,c;
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++) cin >> a[i]; cin >> c;
    for(int i=0;i<(1<<20);i++){
        int bit=0;
        for(int j=1;j<(1<<20);j<<=1) if(j&i) bit++;
        cnt[i]=bit;
    }
    for(int i=1;i<=m;i++) if(cnt[c^a[i]]<=k) ans++;
    cout << ans << '\n';
    return 0;
}