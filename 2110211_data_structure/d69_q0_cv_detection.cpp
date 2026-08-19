#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll cnt[1000500], prevT[1000500];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    while (m--)
    {
        ll p, t;
        cin >> p >> t;
        ll lastTime = t - k;
        if (prevT[p] == 0 || lastTime > prevT[p])
        {
            prevT[p] = t;
            cnt[p]++;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << cnt[i] << '\n';
    return 0;
}

/*
3 6 5
1 1
2 3
1 6
1 7
2 8
3 8
*/