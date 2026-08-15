#include <bits/stdc++.h>
#define newline cout << '\n';
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9 + 7;
const ll infll = 1e18 + 7;

map<string, int> mp;

void solve()
{
    int n;
    cin >> n;
    int mx = -1;
    string ans;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second >= mx)
        {
            mx = it->second;
            ans = it->first;
        }
    }
    cout << ans << ' ' << mx;
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