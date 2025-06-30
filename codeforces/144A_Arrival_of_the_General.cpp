#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;

int mx=0,mn=101;
int lmn,rmn,lmx,rmx;

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int z;
        cin >> z;
        if(z>mx){
            mx=z;
            lmx=i;
            rmx=i;
        }
        else if(z==mx){
            lmx=min(lmx,i);
            rmx=max(rmx,i);
        }
        if(z<mn){
            mn=z;
            lmn=i;
            rmn=i;
        }
        else if(z==mn){
            lmn=min(lmn,i);
            rmn=max(rmn,i);
        }
    }
    if(rmn<lmx) lmx--;
    cout << lmx-1+n-rmn;
    return 0;
}

