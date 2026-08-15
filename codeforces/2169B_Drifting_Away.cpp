#include <bits/stdc++.h>
#define newline cout << "\n";
#define f first
#define s second
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

void solve(){
    string str;
    cin >> str;
    int n = str.length();
    int idx = -1;
    for(int i=1;i<n;i++){
        string res = "";
        res+=str[i-1];
        res+=str[i];
        if(res == "**" || res == "><" || res == "*<" || res == ">*"){
            cout << "-1"; newline
            return;
        }
    }
    for(int i=0;i<n;i++) if(str[i] == '*') idx=i;
    int a = 0, b = 0;
    if(idx != -1) a++, b++;
    for(int i=0;i<n;i++){
        if(str[i] == '<') a++;
        else if(str[i] == '>') b++;
    }
    cout << max(a, b); newline
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}