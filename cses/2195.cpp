#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;

vector<pair<int, int>> points;

signed main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    sort(points.begin(), points.end(), [&](const pii &a, const pii &b){
        return a.first < b.first;
    });
    return 0;
}