#include <bits/stdc++.h>
using namespace std;

void Q1()
{
    cout << "Hello, World!\n";
}

void Q2()
{
    int x;
    cin >> x;
    cout << x << '\n';
}

void Q3()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << sum << '\n';
}

void Q4()
{
    int n;
    cin >> n;
    cin.ignore();
    string ans;
    getline(cin, ans);
    cout << ans << '\n';
}

int main()
{
    int task;
    cin >> task;
    if (task == 1)
        Q1();
    else if (task == 2)
        Q2();
    else if (task == 3)
        Q3();
    else if (task == 4)
        Q4();
    return 0;
}