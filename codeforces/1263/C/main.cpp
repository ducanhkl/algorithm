#include <bits/stdc++.h>

using namespace std;

long long  n;

void solve(long long n)
{
    vector <long long> v;
    long long now = (n+10);
    v.push_back(0);
    while (now > 1)
    {
        long long l = 1, r = now, res = 1;
        while (l <= r)
        {
            long long mid = (l+r)/2;
            if (n/mid == n/now)
            {
                r = mid-1;
            } else
            {
                res = mid, l = mid+1;
            }
        }
        if (n/res != n/now)
        {
            now = res;
            v.push_back(n/now);
        }
    }
    cout << v.size() << endl;
    for (auto num : v)
        cout << num << " ";
    cout << endl;
}

int main()
{
    long long test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        solve(n);
    }
    return 0;
}
