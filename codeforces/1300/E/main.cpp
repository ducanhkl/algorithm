#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+100;

int n, a[maxn], cnt[maxn];
long double b[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int last = 0;
    for (int i = 1; i <= n; i++)
    {
        b[++last] = a[i];
        cnt[last] = 1;
        while (last >= 0 &&
               b[last]/cnt[last] < b[last-1]/cnt[last-1])
        {
            b[last-1]+=b[last];
            cnt[last-1]+=cnt[last];
            last--;
        }
    }
    for (int i = 1; i <= last; i++)
    {
        long double res = b[i];
        res /= cnt[i];
        for (int j = 1; j <= cnt[i]; j++)
        {
            cout << fixed << setprecision(10) << res << " ";
        }
    }
    return 0;
}
