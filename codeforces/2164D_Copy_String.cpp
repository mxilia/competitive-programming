#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n,k;
string a,b,temp;
vector<string> hist;

void solve(){
    cin >> n >> k;
    cin >> a >> b;
    bool ch = false;
    int cnt = 0, len = a.size();
    temp = a;
    for(int i=0;i<k;i++){
        int ptr=len-1;
        while(ptr>=0 && a[ptr]==b[ptr]){ ptr--; }
        if(ptr<0){
            ch = true;
            break;
        }
        for(int j=ptr;j>=0;j--){
            if(ptr>=0 && j<=ptr && a[j]==b[ptr]){
                temp[j]=a[j];
                while(ptr>=0 && j<=ptr && a[j]==b[ptr]){ ptr--; }
            }
            else if(ptr>=0 && j<=ptr && j-1>=0 && a[j-1]==b[ptr]){
                temp[j]=a[j-1];
                while(ptr>=0 && j<=ptr && a[j-1]==b[ptr]){ ptr--; }
            }
            else temp[j]=a[j];
        }
        a = temp;
        hist.push_back(a);
        cnt++;
        ptr=len-1;
        while(ptr>=0 && a[ptr]==b[ptr]){ ptr--; }
        if(ptr<0){
            ch = true;
            break;
        }
    }
    if(ch){
        cout << cnt; newline
        for(auto e:hist) cout << e << "\n";
    }
    else cout << "-1\n";
    hist.clear();
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}

/*
1
10 50
asvavsssa
aaaaasavs
*/