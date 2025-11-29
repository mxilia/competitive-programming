#include <bits/stdc++.h>
#define newline cout << "\n";
#define f first
#define s second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define int long long

int grid[105][105];

void solve(){
    int n;
    cin >> n;
    int cnt=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            grid[i][j]=cnt++;
        }
    }
    int mx = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int sum = grid[i][j];
            if(i-1>=1) sum+=grid[i-1][j];
            if(i+1<=n) sum+=grid[i+1][j];
            if(j-1>=1) sum+=grid[i][j-1];
            if(j+1<=n) sum+=grid[i][j+1];
            mx=max(mx,sum);
        }
    }
    cout << mx;
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

/*
1
6
2 4 6 1 3 5
*/