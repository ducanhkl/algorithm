#include "bits/stdc++.h"

using namespace std;

int m, last = 0;
long long p[100], sum[100];

void solve(int x, vector <int> &v1, vector <int> &v2)
{
    if (x == 0)
        return;
    if (x == 1)
    {
        v2.push_back(1);
        return;
    }
    for (int i = 1; i <= last; i ++)
    {
        if (p[i] <= x && x <= p[i] + sum[i-1])
        {
            v2.push_back(p[i]);
            solve(x-p[i], v1, v2);
            return ;
        }
        if (p[i] - sum[i-1] <= x && x < p[i])
        {
            v2.push_back(p[i]);
            solve(p[i] - x, v2, v1);
            return ;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> m;
    p[0] = 1;
    sum[0] = 1;
    for (int i = 1; p[i-1] < 1e18/3; i++)
    {
        p[i] = p[i-1]*3;
        sum[i] = sum[i-1] + p[i];
        last = i;
    }
    vector <int> v1, v2;
    solve(m, v1, v2);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    cout << v1.size() << " ";
    for (auto v : v1)
        cout << v << " ";
    cout << endl;
    cout << v2.size() << " ";
    for (auto v : v2)
        cout << v << " ";
    return 0;
}