#include <bits/stdc++.h>
#define newline \
    ;           \
    cout << '\n';
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9 + 7;
const ll infll = 1e18 + 7;

void solve()
{
    int n, k, v;
    cin >> n >> k >> v;
    vector<int> in;
    vector<pii> vec;
    for (int i = 0; i < n; i++)
    {
        int z;
        cin >> z;
        in.push_back(z);
    }
    in.insert(in.begin() + k, v);
    int cur = in[0], cnt = 1, itr = -1;
    for (int i = 1; i < in.size(); i++)
    {
        int z = in[i];
        if (i == k + 1)
        {
            itr = vec.size();
        }
        if (z == cur)
        {
            cnt++;
        }
        else
        {
            vec.push_back({cur, cnt});
            cur = z;
            cnt = 1;
        }
    }
    vec.push_back({cur, cnt});
    int l = -inf, r = -inf;
    k = itr;
    if (vec[k].second >= 3)
    {
        l = k - 1;
        r = k + 1;
    }
    while (l >= 0 && r < vec.size())
    {
        if (vec[l].first == vec[r].first && vec[l].second + vec[r].second >= 3)
        {
            l--;
            r++;
        }
        else
            break;
    }
    for (int i = 0; i < vec.size(); i++)
    {
        if (l == -inf || i <= l || i >= r)
        {
            for (int j = 0; j < vec[i].second; j++)
            {
                cout << vec[i].first << ' ';
            }
        }
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
/*
3 1 10
2 3 4
*/