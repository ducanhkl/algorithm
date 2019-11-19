#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int d[maxn], a[maxn], k, n = 0;
long long ans = 0;
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> k;
    char x;
    while (cin >> x)
        a[++n] = x-'0';
    if (k == 0)
    {
        for (int i = 1; i <= n; i++)
            if (a[i] == 0)
                ans ++;
        cout << ans;
        return 0;
    }
    for (int i = 1; i <= n; i++)
        if (a[i] == 1)
            d[i] ++;
    for (int i = 1; i <= n; i++)
        d[i] += d[i-1];
    for (int i = 1; i <= n; i++)
    {
        long long f = lower_bound(d+1, d+i+1, d[i]-k)-d;
        long long s = upper_bound(d+1, d+i+1, d[i]-k)-d;
        if (d[f] != (d[i]-k))
            continue;
        ans += min(s, (long long)i) - f + 1;
    }
    cout << ans;
    return 0;
}
