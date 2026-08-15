#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;

int fa[105],fb[105];

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n,m;
    cin >> n;
    for(int i=0;i<n;i++){
        int z;
        cin >> z;
        fa[z]++;
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int z;
        cin >> z;
        fb[z]++;
    }
    int sum=0;
    for(int i=1;i<=100;i++){
        if(fa[i-1] && fb[i]){
            int mn=min(fa[i-1],fb[i]);
            sum+=mn;
            fa[i-1]-=mn;
            fb[i]-=mn;
        }
        if(fb[i-1] && fa[i]){
            int mn=min(fb[i-1],fa[i]);
            sum+=mn;
            fb[i-1]-=mn;
            fa[i]-=mn;
        }
        if(fa[i] && fb[i]){
            int mn=min(fa[i],fb[i]);
            sum+=mn;
            fa[i]-=mn;
            fb[i]-=mn;
        }
    }
    cout << sum;
    return 0;
}

