#include <bits/stdc++.h>
#define newline cout << '\n';
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9 + 7;
const ll infll = 1e18 + 7;

vector<int> a;

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int z;
        cin >> z;
        a.push_back(z);
    }
    sort(a.begin(), a.end());
    while (m--)
    {
        int x;
        cin >> x;
        int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
        if (idx == 0)
        {
            cout << a[idx];
        }
        else if (idx == n)
        {
            cout << a[n - 1];
        }
        else
        {
            if (x - a[idx - 1] < a[idx] - x)
            {
                cout << a[idx - 1];
            }
            else
            {
                cout << a[idx];
            }
        }
        cout << ' ';
    }
    a.clear();
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