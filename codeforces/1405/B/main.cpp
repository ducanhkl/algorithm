#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

int n;
long long a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int r = 2;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] < 0)
                continue;
            r = max(r, i+1);
            while (a[r] > 0 && r <= n)
                r++;
            while (a[i] != 0)
            {
                if (r == n+1)
                    break;
                if (a[r] > 0)
                {
                    r++;
                    continue;
                }
                if (a[i] > abs(a[r]))
                {
                    a[i] += a[r];
                    a[r] = 0;
                    r ++;
                } else
                {
                    a[r] += a[i];
                    a[i] = 0;
                }
            }
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] > 0)
                ans += a[i];
        cout << ans << endl;
    }
    return 0;
}
