#include <bits/stdc++.h>
#define newline cout << '\n';
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int shift[100500];
map<string, bool> mp;

char plus_char(char c, int s)
{
    return 'a' + (((c - 'a') + s) % 26);
}

void solve()
{
    int n, m, l;
    cin >> n >> m >> l;
    for (int i = 0; i < l; i++)
        cin >> shift[i];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mp[s] = true;
    }
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
            s[j] = plus_char(s[j], shift[j]);
        if (mp[s])
            cout << "Match\n";
        else
            cout << "Unknown\n";
    }
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