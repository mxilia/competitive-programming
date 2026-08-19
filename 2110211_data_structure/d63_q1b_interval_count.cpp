#include <bits/stdc++.h>
#define newline cout << '\n';
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9 + 7;
const ll infll = 1e18 + 7;

vector<int> vec;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        int z;
        cin >> z;
        vec.push_back(z);
    }
    sort(vec.begin(), vec.end());
    for (int q = 0; q < m; q++)
    {
        int x;
        cin >> x;
        int l = x - k, r = x + k;
        int ldx = lower_bound(vec.begin(), vec.end(), l) - vec.begin();
        int rdx = upper_bound(vec.begin(), vec.end(), r) - vec.begin();
        int cnt = rdx - ldx;
        cout << cnt << ' ';
    }
    vec.clear();
    return;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int t(1);
    // cin >> t;
    while (t--)
        solve();
    return 0;
}