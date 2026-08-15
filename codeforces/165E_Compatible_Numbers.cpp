#include <bits/stdc++.h>
#define newline cout << "\n";
using ll = long long;
using namespace std;
const int bit = 22;

int a[1000005], dp[1<<bit];

signed main() {
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i=1;i<=n;i++){
        cin >> a[i];
        dp[a[i]] = a[i];
    }
    for(int i=0;i<(1<<bit);i++){
        for(int j=0;j<bit;j++){
            if(i&(1<<j) && dp[i^(1<<j)] != -1) {
                dp[i]=dp[i^(1<<j)];
            }
        }
    }
    for(int i=1;i<=n;i++){
        int temp = ((1<<bit)-1)^a[i];
        cout << dp[temp] << " ";
    }
    return 0;
}