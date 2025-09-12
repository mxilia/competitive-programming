#include <bits/stdc++.h>
#define newline cout << '\n';
using namespace std;
const int inf=1e9+7;
const int md=3e6+17;

bool flag[md+5];
int idx[md+5];
int hash_val[md+5];
set<int> ans;

int hash_str(string s){
    int h=0;
    for(int i=0;i<s.length();i++) h=((h<<1)+(s[i]-'0'));
    return h;
}

void add_hash(string s,int idx){
    int hash_val=hash_str(s);
    int temp=hash_val%md;
    while(flag[temp]) temp=(temp+1)%md;
    flag[temp]=1;
    ::idx[temp]=idx;
    ::hash_val[temp]=hash_val;
}

void solve(){
    int k,m,n;
    cin >> k >> m;
    for(int i=0;i<k;i++){
        string s;
        cin >> s;
        add_hash(s,i+1);
    }
    cin >> n;
    while(n--){
        int l; string s;
        cin >> l >> s;
        int h=0;
        for(int i=0;i<l;i++){
            h=(h<<1)+(s[i]-'0');
            if(i>=m-1){
                int temp=h%md;
                while(flag[temp]){
                    if(hash_val[temp]==h){
                        ans.insert(idx[temp]);
                        break;
                    }
                    temp=(temp+1)%md;
                }
                h=h-((s[i+1-m]-'0')<<(m-1));
            }
        }
        if(ans.empty()) cout << "OK";
        else {
            for(auto e:ans) cout << e << ' ';
            ans.clear();
        }
        newline
    }
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t(1);
    //cin >> t;
    while(t--) solve();
    return 0;
}