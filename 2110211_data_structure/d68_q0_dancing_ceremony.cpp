#include <bits/stdc++.h>
#define newline cout << '\n';
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9 + 7;
const ll infll = 1e18 + 7;

ll a[200005], b[200005];
vector<ll> diff;

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    diff.push_back(-infll);
    for (int i = 0; i < n; i++)
    {
        diff.push_back(a[i] - b[i]);
    }
    sort(diff.begin(), diff.end());
    ll itr = n, ans = 0;
    for (int i = 1; i < n; i++)
    {

        while (itr > 1 && diff[i] + diff[itr] > 0)
        {
            itr--;
        }
        if (itr > i)
        {
            ans += n - itr;
        }
        else
        {
            ans += n - i;
        }
    }
    cout << ans;
    newline;
    diff.clear();
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