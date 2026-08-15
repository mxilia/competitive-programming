#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;
const int N=1000500;
const ll B=1e6;

ll a[B+10];
bool flag[B+10];

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    memset(flag,1,sizeof(flag));
    flag[1]=false;
    for(ll i=2;i*i<=B;i++){
        if(!flag[i]) continue;
        for(ll j=i*i;j<=B;j+=i) flag[j]=false;
    }
    for(int i=0;i<n;i++){
        ll sq=(ll)sqrt(a[i]);
        if(sq*sq==a[i] && flag[sq]) cout << "YES";
        else cout << "NO";
        newline
    }
    return 0;
}

