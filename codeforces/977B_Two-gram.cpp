#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;

map<string, int> mp;
int mx;

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    string s,ans;
    cin >> n >> s;
    for(int i=0;i<n-1;i++){
        mp[s.substr(i,2)]++;
        if(mp[s.substr(i,2)]>mx){
            mx=mp[s.substr(i,2)];
            ans=s.substr(i,2);
        }
    }
    cout << ans;
    return 0;
}