#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int N=2e5;

int n,m;
pii monster[200500];
vector<int> remain;
priority_queue<int,vector<int>,greater<int>> pq;

void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int z; cin >> z;
        pq.push(z);
    }
    for(int i=1;i<=m;i++) cin >> monster[i].first;
    for(int i=1;i<=m;i++) cin >> monster[i].second;
    sort(monster+1,monster+m+1);
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(monster[i].second == 0) continue;
        while(!pq.empty() && pq.top()<monster[i].first){
            remain.push_back(pq.top());
            pq.pop();
        }
        if(pq.empty()) break;
        int new_sword = max(monster[i].second,pq.top());
        pq.pop();
        pq.push(new_sword);
        cnt++;
    }
    while(!pq.empty()) remain.push_back(pq.top()), pq.pop();
    int ptr=0;
    for(int i=1;i<=m;i++){
        if(monster[i].second) continue;
        while(ptr<remain.size() && remain[ptr]<monster[i].first) ptr++;
        if(ptr>=remain.size()) break;
        ptr++;
        cnt++;
    }
    cout << cnt; newline
    remain.clear();
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

/*
#include <bits/stdc++.h>
#define newline cout << "\n";
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int N=2e5;
 
int n,m;
 
struct max_segment
{
    int tree[5*N],index[5*N];
    void update(int i,int val,int l=1,int r=m,int idx=1){
        if(i<l || r<i) return;
        if(l==r){
            tree[idx]=val;
            index[idx]=i;
            return;
        }
        int mid=(l+r)/2;
        update(i,val,l,mid,2*idx), update(i,val,mid+1,r,2*idx+1);
        if(tree[2*idx]>tree[2*idx+1]){
            tree[idx]=tree[2*idx];
            index[idx]=index[2*idx];
        }
        else {
            tree[idx]=tree[2*idx+1];
            index[idx]=index[2*idx+1];
        }
        return;
    }
 
    pii query(int a,int b,int l=1,int r=m,int idx=1){ 
        if(b<l || r<a) return {0, 0};
        if(a<=l && r<=b) return {tree[idx], index[idx]};
        int mid=(l+r)/2;
        pii lval=query(a,b,l,mid,2*idx),rval=query(a,b,mid+1,r,2*idx+1);
        return max(lval, rval);
    }
} mx_tree;
 
multiset<int> sword, remain;
pii monster[200050];
int health[200500];
priority_queue<int> pq[200500];
map<int,bool> mp;
vector<int> compress;
 
int get_compressed_index(int h){
    auto itr = lower_bound(compress.begin(),compress.end(),h);
    return itr-compress.begin();
}
 
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int z;
        cin >> z;
        sword.insert(z);
    }
    for(int i=1;i<=m;i++){
        cin >> monster[i].first;
        compress.push_back(monster[i].first);
    }
    for(int i=1;i<=m;i++){
        cin >> monster[i].second;
    }
    sort(monster+1,monster+m+1);
    sort(compress.begin(),compress.end());
    compress.erase(unique(compress.begin(),compress.end()),compress.end());
    for(int i=1;i<=m;i++){
        remain.insert(monster[i].first);
        mx_tree.update(i,monster[i].second);
        health[i]=monster[i].first;
        pq[get_compressed_index(health[i])].push(i);
    }
    int cnt=0;
    while(true){
        if(sword.empty() || remain.empty()) break;
        
        int mx_sword = *(--sword.end());
        auto itr = remain.upper_bound(mx_sword);
        if(itr != remain.begin()) itr--;
        if(*itr>mx_sword) break;
        
        for(auto e:sword) cout << e << ", "; newline
        cout << "sword: " << *(--sword.end()); newline
        for(auto e:remain) cout << e << ", "; newline
        cout << "far: " << *itr; newline
        
        int citr = get_compressed_index(*itr);
        while(!pq[citr].empty() && mp[pq[citr].top()]) pq[citr].pop();
        if(pq[citr].empty()) break;
        int idx = pq[citr].top();
        //cout << "citr: " << citr << " mx_idx: " << idx; newline
        pii mx = mx_tree.query(1,idx);
        mp[mx.second] = true;
 
        //cout << "mx: h: " << health[mx.second] << " c: " << mx.first << " idx: " << mx.second; newline
        
        if(mx.first == -1) break;
        remain.erase(remain.find(health[mx.second]));
        mx_tree.update(mx.second, -1);
 
        auto itr2 = sword.lower_bound(health[mx.second]);
        if(mx.first>0){
            int new_sw = max(mx.first, *itr2);
            sword.insert(new_sw);
        }
        sword.erase(itr2);
        cnt++;
    }
    cout << cnt; newline
    mp.clear();
    sword.clear();
    remain.clear();
    compress.clear();
    for(int i=0;i<=m;i++) while(!pq[i].empty()) pq[i].pop();
    return;
}
 
signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
*/
/*
1
3 5
1 7 7
6 6 2 2 2
2 0 0 7 2
----
1
4 4
1 5 3 5
7 4 6 5
0 0 1 6
*/