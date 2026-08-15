#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;

int a[105],b[105];
int m,s,sum,mnch,mxch;

void printArr(int arr[]){
    for(int i=0;i<m;i++) cout << arr[i];
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> m >> s;
    if(s==0 && m==1){
        cout << "0 0";
        return 0;
    }
    a[0]=1;
    sum++;
    if(sum==s) mnch=1;
    for(int i=m-1;i>=0;i--){
        if(mnch) break;
        while(a[i]<9){
            a[i]++;
            sum++;
            if(sum==s){
                mnch=1;
                break;
            }
        }
    }
    sum=0;
    b[0]=1;
    sum++;
    if(sum==s) mxch=1;
    for(int i=0;i<m;i++){
        if(mxch) break;
        while(b[i]<9){
            b[i]++;
            sum++;
            if(sum==s){
                mxch=1;
                break;
            }
        }
    }
    if(mnch) printArr(a);
    else cout << "-1";
    cout << ' ';
    if(mxch) printArr(b);
    else cout << "-1";
    return 0;
}