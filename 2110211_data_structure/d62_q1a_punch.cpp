#include <iostream>
#include <vector>
using namespace std;

vector<string> punch(vector<string> &v, vector<string>::iterator it, int k)
{
    vector<string> res;
    int idx = it - v.begin();
    for (int i = 0; i < v.size(); i++)
    {
        if (idx - k > i || i > idx + k)
        {
            res.push_back(v[i]);
        }
    }
    return res;
}

int main()
{
    int n, j, k;
    cin >> n >> j >> k;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << "Result after punch" << endl;
    vector<string> result = punch(v, v.begin() + j, k);
    for (auto &x : result)
    {
        cout << x << endl;
    }
}