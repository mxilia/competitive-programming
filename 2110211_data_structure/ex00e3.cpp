#include <bits/stdc++.h>
#define newline cout << '\n';
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9 + 7;
const ll infll = 1e18 + 7;

map<ll, bool> mp;

void solve()
{
    int n, ch = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ll z;
        cin >> z;
        if (mp[z] || z < 1 || z > n)
        {
            ch = true;
        }
        mp[z] = true;
    }
    if (ch)
        cout << "NO";
    else
        cout << "YES";
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