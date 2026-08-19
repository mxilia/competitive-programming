#include <bits/stdc++.h>
#define newline cout << '\n';
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = 1e9 + 7;
const ll infll = 1e18 + 7;

vector<int> a, b;

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
    for (int i = 0; i < m; i++)
    {
        int z;
        cin >> z;
        b.push_back(z);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int itr = 0;
    for (int i = 0; i < a.size(); i++)
    {
        while (itr < b.size() - 1 && b[itr] < a[i])
            itr++;
        if (b[itr] == a[i])
            cout << a[i] << ' ';
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