#include <bits/stdc++.h>
#define newline cout << '\n';
#define test cout << "test: " <<
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9 + 7;
const ll infll = 1e18 + 7;

set<pii> s;

void solve()
{
    int n, q, sum;
    cin >> n >> q;
    sum = n;
    for (int i = 0; i < q; i++)
    {
        int l, r, newl, newr;
        cin >> l >> r;
        sum -= r - l + 1;
        newl = l, newr = r;
        auto ltr = s.lower_bound({l, -1});
        if (ltr != s.begin())
        {
            auto prv = prev(ltr);
            if (prv->second >= l)
            {
                ltr = prv;
            }
        }
        vector<set<pii>::iterator> erase;
        while (ltr != s.end() && ltr->first <= r)
        {
            sum += min(r, ltr->second) - max(l, ltr->first) + 1;
            newl = min(newl, ltr->first);
            newr = max(newr, ltr->second);
            erase.push_back(ltr);
            ltr++;
        }
        for (auto &e : erase)
        {
            s.erase(e);
        }
        s.insert({newl, newr});
        cout << sum << '\n';
    }
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

/*
10 5
1 2
1 2
1 2
1 2
1 2
*/