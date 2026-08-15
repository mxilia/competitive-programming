#include <bits/stdc++.h>
#define newline cout << "\n";
#define int long long
using namespace std;
const int N=400500;

struct A
{
    int l,r,idx;
    bool operator<(const A &o)const{
        if(l==o.l) return r<o.r;
        return l>o.l;
    }
};

int mn=1e9,mx=0;

struct segment
{
    int tree[8*N];
    void update(int i,int val,int l=mn,int r=mx,int idx=1){
        if(i<l || r<i) return;
        if(l==r){
            tree[idx]=max(tree[idx],val);
            return;
        }
        int mid=(l+r)/2;
        update(i,val,l,mid,2*idx), update(i,val,mid+1,r,2*idx+1);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
        return;
    }
    int query(int a,int b,int l=mn,int r=mx,int idx=1){
        if(b<l || r<a) return 0;
        if(a<=l && r<=b) return tree[idx];
        int mid=(l+r)/2;
        return max(query(a,b,l,mid,2*idx),query(a,b,mid+1,r,2*idx+1));
    }
};

vector<A> vec;
vector<int> compress;
int ans[400500];
segment seg;

void solve_seg(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int l,r;
        cin >> l >> r;
        vec.push_back({l,r,i});
        compress.push_back(l), compress.push_back(r);
    }
    sort(compress.begin(),compress.end());
    compress.erase(unique(compress.begin(),compress.end()),compress.end());
    for(int i=0;i<n;i++){
        vec[i].l=lower_bound(compress.begin(),compress.end(),vec[i].l)-compress.begin()+1;
        vec[i].r=lower_bound(compress.begin(),compress.end(),vec[i].r)-compress.begin()+1;
        mx=max({mx,vec[i].l,vec[i].r});
        mn=min({mn,vec[i].l,vec[i].r});
    }
    sort(vec.begin(),vec.end());
    int cnt=0;
    for(int i=0;i<n;i++){
        ans[vec[i].idx]=seg.query(vec[i].l+1,vec[i].r)+1;
        seg.update(vec[i].r,ans[vec[i].idx]);
        cnt=max(cnt,ans[vec[i].idx]);
    }
    cout << cnt; newline
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    return;
}

int lis[400500];

void solve_lis(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int l,r;
        cin >> l >> r;
        vec.push_back({l,r,i});
    }
    sort(vec.begin(),vec.end());
    int sz=0,mx=0;
    for(int i=0;i<n;i++){
        int idx=upper_bound(lis,lis+sz,vec[i].r)-lis;
        if(idx==sz) sz++;
        lis[idx]=vec[i].r;
        ans[vec[i].idx]=idx+1;
        mx=max(mx,idx+1);
    }
    cout << mx; newline
    for(int i=1;i<=n;i++) cout << ans[i] << " ";
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    solve_seg();
    //solve_lis();
    return 0;
}
