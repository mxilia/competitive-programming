#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int h, m;
    cin >> h >> m;
    int x;
    cin >> x;
    int hn, mn;
    hn = h;
    mn = m;
    int nhn, nmn;
    nmn = (mn + (x % 60)) % 60;
    nhn = (hn + x / 60 + ((mn + (x % 60)) >= 60)) % 24;
    cout << (nhn < 10 ? "0" : "") << nhn << " " << (nmn < 10 ? "0" : "") << nmn;
}