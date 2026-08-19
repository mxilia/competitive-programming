#include <bits/stdc++.h>
#define newline cout << '\n';
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int inf = 1e9 + 7;
const ll infll = 1e18 + 7;

vector<pii> p;

ll cal_dist(pll s, pll e, ll r, ll c)
{
    if (e.first == s.first)
    {
        return e.second - s.second;
    }
    return c - s.second + e.second + (e.first - s.first - 1) * c;
}

void solve()
{
    int r, c, k;
    cin >> r >> c >> k;
    for (int i = 0; i < k; i++)
    {
        int ri, ci;
        cin >> ri >> ci;
        p.push_back({ri, ci});
    }
    sort(p.begin(), p.end());
    int q;
    cin >> q;
    while (q--)
    {
        int si, sj;
        cin >> si >> sj;
        auto next = upper_bound(p.begin(), p.end(), make_pair(si, sj));
        auto temp = next;
        temp--;
        if (temp->first == si && temp->second == sj)
        {
            cout << 0;
        }
        else if (next == p.end())
        {
            cout << cal_dist({si, sj}, {r, c}, r, c) + cal_dist({1, 1}, {p.begin()->first, p.begin()->second}, r, c) + 1;
        }
        else
        {
            cout << cal_dist({si, sj}, {next->first, next->second}, r, c);
        }
        newline;
    }
    p.clear();
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
/*
2 5 1
1 3
2
1 2
1 4
*/