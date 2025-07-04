#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;
const int inf=1e9+7;

int s[2005];
map<int,int> f;

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s[i];
        f[s[i]]++;
    }
    
    return 0;
}