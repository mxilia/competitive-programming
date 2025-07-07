#include <bits/stdc++.h>
#define newline cout << "\n";
#define f first
#define s second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int inf=1e9+7;

struct A
{
    int t,x,idx;
    bool operator<(const A &o)const{
        if(t==o.t) return x>o.x;
        return t<o.t;
    }
};

pii arr[200500];
vector<A> event;
void solve(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int l,r;
        cin >> l >> r;
        arr[i]=make_pair(l,r);
        event.push_back({l,1,i});
        event.push_back({r+1,-1,i});
    }
    sort(event.begin(),event.end());
    
    event.clear();
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}