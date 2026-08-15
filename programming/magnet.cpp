/*
    task: MagnetYTOPC
*/

#include <bits/stdc++.h>
#define newline cout << "\n";
#define f first
#define s second
#define pii pair<int,int>
using namespace std;

vector<int> vec,ans;

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    while(m--){
        int l,r;
        cin >> l >> r;
        vec.push_back(l);
        vec.push_back(l+r);
    }
    ans.push_back(1);
    sort(vec.begin(),vec.end());
    int sz=vec.size();
    for(int i=0;i<sz;i++){
        if(vec[i]==vec[i+1]){
            i++;
            continue;
        }
        ans.push_back(vec[i]);
    }
    ans.push_back(n+1);
    while(q--){
        int p;
        cin >> p;
        int idx=upper_bound(ans.begin(),ans.end(),p)-ans.begin();
        cout << ans[idx]-ans[idx-1]; newline
    }
    return 0;
}