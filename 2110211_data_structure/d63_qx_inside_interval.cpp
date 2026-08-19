#include <bits/stdc++.h>
#define newline cout << '\n';
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9 + 7;
const ll infll = 1e18 + 7;

vector<pii> vec;

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        vec.push_back({l, r});
    }
    sort(vec.begin(), vec.end());
    while (m--)
    {
        int x;
        cin >> x;
        int idx = upper_bound(vec.begin(), vec.end(), (pii){x, inf}) - vec.begin();
        cout << (int)((idx != 0) && (vec[idx - 1].second >= x)) << ' ';
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