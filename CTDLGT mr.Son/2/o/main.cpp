#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3+100, maxc = 1e4+100;
const long long long_max = 1e18;
long long a[maxn], n, b[maxn], ans = long_max;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int i = 1; i <= n; i++)
            b[i] = a[i];
        long long p = 0;
        for (int j = 1; j < i; j++)
        {
            b[j] += p;
            p --;
        }
        for (int j = i; j <= n; j++)
        {
            b[j] += p;
            p++;
        }
        sort(b+1, b+n+1);
        long long tv = max(b[(n+1)/2], 0LL), res = 0;
        for (int j = 1; j <= n; j++)
        {
            res += abs(tv - a[j]);
            if (j < i)
                tv++;
            else
                tv--;
        }
        ans = min(ans, res);
    }
    cout << ans;
    return 0;
}
