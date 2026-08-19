#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[100500], b[100500];
vector<int> diff;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, k, d;
    cin >> n >> k >> d;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < n; j++)
    {
        cin >> b[j];
    }
    for (int i = 0; i < n; i++)
    {
        diff.push_back(a[i] - b[i]);
    }
    sort(diff.begin(), diff.end());
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int needed = k - diff[i];
        if (needed - diff[i] > d)
        {
            continue;
        }
        auto itr = lower_bound(diff.begin(), diff.end(), needed);
        int mx = upper_bound(diff.begin(), diff.end(), d + diff[i]) - diff.begin();
        int idx = max(i + 1, (int)(itr - diff.begin()));
        if (idx > (n - 1))
            continue;
        cnt += mx - idx;
    }
    cout << cnt;
}