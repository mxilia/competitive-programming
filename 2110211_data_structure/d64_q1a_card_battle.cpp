#include <bits/stdc++.h>
#define newline cout << '\n';
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9 + 7;
const ll infll = 1e18 + 7;

multiset<int> s;

void solve()
{
    int n, m, lose = 0, ans = 1;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int z;
        cin >> z;
        s.insert(z);
    }
    for (int i = 1; i <= m; i++)
    {
        int o;
        cin >> o;
        for (int j = 0; j < o; j++)
        {
            int k;
            cin >> k;
            if (lose)
                continue;
            auto itr = s.upper_bound(k);
            if (itr == s.end())
                lose = true;
            else
                s.erase(itr);
        }
        if (lose)
            continue;
        ans++;
    }
    cout << ans;
    s.clear();
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