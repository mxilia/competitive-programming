#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;

ll a[200500],sum[200500],mxl[200500],mxr[200500],mx,s;
int ldx[200500],rdx[200500],adx;

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=k;i++) s+=a[i];
    sum[1]=s;
    for(int i=2;i<=n-k+1;i++){
        s=s-a[i-1]+a[i+k-1];
        sum[i]=s;
    }
    for(int i=k;i<=n-k+1;i++){
        if(mxl[i-1]>=sum[i-k+1]){
            mxl[i]=mxl[i-1];
            ldx[i]=ldx[i-1];
        }
        else {
            mxl[i]=sum[i-k+1];
            ldx[i]=i-k+1;
        }
    }
    for(int i=n-k+1;i>=k;i--){
        if(sum[i]<mxr[i+1]){
            mxr[i]=mxr[i+1];
            rdx[i]=rdx[i+1];
        }
        else {
            mxr[i]=sum[i];
            rdx[i]=i;
        }
    }
    for(int i=k+1;i<=n-k+1;i++){
        if(mxl[i-1]+mxr[i]>mx){
            mx=mxl[i-1]+mxr[i];
            adx=i;
        }
    }
    cout << ldx[adx-1] << ' ' << rdx[adx];
    return 0;
}