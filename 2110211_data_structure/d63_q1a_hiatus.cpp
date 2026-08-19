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
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < m; i++)
    {
        int y, m;
        cin >> y >> m;
        int idx = lower_bound(vec.begin(), vec.end(), make_pair(y, m)) - vec.begin();
        if (idx >= n || !(vec[idx].first == y && vec[idx].second == m))
        {
            if (idx == 0)
            {
                cout << "-1 -1 ";
            }
            else
                cout << vec[idx - 1].first << " " << vec[idx - 1].second << " ";
        }
        else
            cout << "0 0 ";
    }
    vec.clear();
    return;
}

signed main()
{
    // ios::sync_with_stdio(0), cin.tie(0);
    int t(1);
    // cin >> t;
    while (t--)
        solve();
    return 0;
}