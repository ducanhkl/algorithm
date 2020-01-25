#include "bits/stdc++.h"

using namespace std;

long long po[100], sum[100], last;

bool solve(long long p, long long val)
{
    if (val == 0)
        return true;
    if (val == 1)
        return true;
    for (int pos = 1; pos <= last; pos ++)
    {
        if (po[pos] - sum[pos-1] <= val && val < po[pos])
        {
            return solve(p, po[pos] -val);
        }
        if (po[pos] <= val && val <= po[pos] + sum[pos-1])
        {
            return solve(p, val - po[pos]);
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    po[0] = 1;
    sum[0] = 1;
    while (test--)
    {
        long long n, m;
        cin >> n >> m;
        last = 0;
        for (int i = 1; po[i-1] <= 1e18/n; i++)
            po[i] = po[i-1]*n, last = i;
        for (int i = 1; i <= last; i++)
            sum[i] = sum[i-1] + po[i];
        if (solve(n, m))
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}