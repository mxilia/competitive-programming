#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;

int n,q;

struct segment
{
    ll a[2<<19];

    int update(ll val,int i,bool opr,int l=1,int r=1<<n,int idx=1){
        if(i<l || r<i) return a[idx];
        if(l==r){
            a[idx]=val;
            return a[idx];
        }
        int mid=(l+r)/2;
        ll left=update(val,i,!opr,l,mid,2*idx); 
        ll right=update(val,i,!opr,mid+1,r,2*idx+1);
        if(opr==1) a[idx]=left|right;
        else a[idx]=left^right;
        return a[idx];
    }
} tree;

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for(int i=1;i<=(1<<n);i++){
        ll z;
        cin >> z;
        tree.update(z,i,n%2);
    }
    while(q--){
        int p; ll b;
        cin >> p >> b;
        cout << tree.update(b,p,n%2);
        newline
    }
    return 0;
}