#include <bits/stdc++.h>
#define newline cout << "\n";
#define f first
#define s second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define int long long

struct A
{
    int t,l,h;
};

vector<A> vec;

void solve(){
    int n,h;
    cin >> n >> h;
    for(int i=1;i<=n;i++){
        int t,l,h;
        cin >> t >> l >> h;
        vec.push_back({t,l,h});
    }
    int ct=0,cl=h,ch=h,ok=true;
    int dt=vec[0].t;
    if(vec[0].l>ch){
        int dist=abs(vec[0].l-ch);
        if(dist>dt) ok=false;
    }
    else if(vec[0].h<cl){
        int dist=abs(cl-vec[0].h);
        if(dist>dt) ok=false;
    }
    ch=min(vec[0].h,ch+dt);
    cl=max(vec[0].l,cl-dt);
    for(int i=0;i<vec.size()-1;i++){
        if(!ok) break;
        int dt=abs(vec[i].t-vec[i+1].t);
        if(vec[i+1].l>ch){
            int dist=abs(vec[i+1].l-ch);
            if(dist>dt) ok=false;
        }
        else if(vec[i+1].h<cl){
            int dist=abs(cl-vec[i+1].h);
            if(dist>dt) ok=false;
        }
        if(!ok) break;
        ch=min(vec[i+1].h,ch+dt);
        cl=max(vec[i+1].l,cl-dt);
        int temp=ch;
        ch=max(temp,cl);
        cl=min(temp,cl);
    }
    if(ok) cout << "Yes";
    else cout << "No";
    newline
    vec.clear();
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t(1);
    cin >> t;
    while(t--) solve();
    return 0;
}

/*
1
6
2 4 6 1 3 5
*/