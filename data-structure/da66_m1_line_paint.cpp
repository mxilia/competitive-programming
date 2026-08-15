#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> p;
vector<int> ans;

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        p.push_back({l, r});
    }
    sort(p.begin(), p.end());
    int l = p[0].first, r = p[0].second;
    for (int i = 1; i < n; i++)
    {
        if (p[i].first <= r + 1)
        {
            r = max(r, p[i].second);
        }
        else
        {

            ans.push_back(l);
            ans.push_back(r);
            l = p[i].first;
            r = p[i].second;
        }
    }
    ans.push_back(l);
    ans.push_back(r);
    for (auto e : ans)
    {
        cout << e << ' ';
    }
    return 0;
}