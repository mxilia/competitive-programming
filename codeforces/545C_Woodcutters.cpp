#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;
const int inf=1e9+7;

struct A
{
    ll s,e;
    bool operator<(const A &o)const{
        return e<o.e;
    }
};

ll x[100500],h[100500];
vector<A> vec;

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> x[i] >> h[i];
    x[0]=-2e18; x[n+1]=2e18;
    for(int i=1;i<=n;i++){
        if(x[i]+h[i]<x[i+1]) vec.push_back({x[i],x[i]+h[i]});
        if(x[i]-h[i]>x[i-1]) vec.push_back({x[i]-h[i],x[i]});
    }
    sort(vec.begin(),vec.end());
    ll end=-2e18,cnt=0;
    for(auto e:vec){
        if(end<e.s){
            end=e.e;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}