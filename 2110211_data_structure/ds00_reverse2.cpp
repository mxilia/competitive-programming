#include <iostream>
#include <vector>
using namespace std;

void reverse(vector<int> &v, vector<int>::iterator a, vector<int>::iterator b)
{
    int l = a - v.begin(), r = b - v.begin() - 1;
    while (l < r)
        swap(v[l++], v[r--]);
}

int main()
{
    // read input
    int n, a, b;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;
    // call function
    reverse(v, v.begin() + a, v.begin() + b + 1);
    // display content of the vector
    for (auto &x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

/*
6 0 1
1 2 3 4 5 6
*/