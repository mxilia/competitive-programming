#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int dp[105][105];

void solve()
{
    int n, m;
    cin >> n >> m;
    int q;
    cin >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> dp[i][j];
        }
    }
    while (q--)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 > r2 || c1 > c2)
        {
            cout << "INVALID\n";
            continue;
        }
        if (r1 > n || c1 > m || r2 < 1 || c2 < 1)
        {
            cout << "OUTSIDE\n";
            continue;
        }
        int mx = -inf;
        r2 = min(n, r2);
        c2 = min(m, c2);
        for (int i = r1; i <= r2; i++)
        {
            for (int j = c1; j <= c2; j++)
            {
                mx = max(mx, dp[i][j]);
            }
        }
        cout << mx << '\n';
    }
    return;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int q(1);
    // cin >> q;
    while (q--)
        solve();
    return 0;
}