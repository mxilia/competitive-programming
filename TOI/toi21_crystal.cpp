#include <bits/stdc++.h>
#define newline cout << '\n';
using namespace std;
const int inf=1e9+7;
using pii = pair<int,int>;
using ll = long long;

struct A
{
    A(int p=0, int w=0, int t=0): p(p), w(w), t(t){}
    int p,w,t;
    bool operator<(const A &o)const{
        return t<o.t;
    }
};

vector<A> crys;
deque<A> dq;

void solve(){
    int u,k,n;
    cin >> u >> k >> n;
    for(int i=0;i<n;i++){
        int p,w,t;
        cin >> p >> w >> t;
        crys.emplace_back(p,w,t);
    }
    sort(crys.begin(), crys.end());
    
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t(1);
    // cin >> t;
    while(t--) solve();
    return 0;
}