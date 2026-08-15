#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;
const int inf=1e9+7;

double a[100500];
int sum;
bool flag[100500];

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]-floor(a[i])==0) flag[i]=1;
        a[i]=floor(a[i]);
        sum+=(int)a[i];
    }
    for(int i=1;i<=n;i++){
        if(sum && !flag[i]){
            sum++;
            a[i]+=1;
        }
    }
    for(int i=1;i<=n;i++) cout << a[i] << '\n';
    return 0;
}