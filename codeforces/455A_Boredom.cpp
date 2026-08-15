#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;

ll dp[100500],a[100500],f[100500],mx;

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        f[a[i]]++;
        mx=max(mx,a[i]);
    }
    for(int i=1;i<=mx;i++) dp[i]=max(dp[i-1],f[i]*i+dp[max(0,i-2)]);
    cout << dp[mx];
    return 0;
}