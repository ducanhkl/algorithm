#include <bits/stdc++.h>

using namespace std;

long long n, m, k;
long long c[maxn], f[4][maxn], cnt[4];

int main()
{
    memset(cnt, 0, sizeof(cnt));
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    cin >> s;
    for (int i = 1; i <= s; i++)
    {
        int x;
        cin >> x;
        a[x] += 1;
    }
    cin >> s;
    for (int i = 1; i <= s; i++)
    {
        int x;
        cin >> s;
        a[x] += 2;
    }
    for (int i = 1; i <= n; i++)
        f[a[i]][++cnt[a[i]]] = c[i];
    for (int i = 1; i <= 3; i++)
        sort(f[i] + 1, f[i] + cnt[i] + 1);
    for (int i = 0; i <= min(cnt[3], k); i++)
    {
        if (k - i > min(cnt[1], cnt[2]))
            continue;
        if (2*k-i>m)
            continue;
        long long l = 0, r = 1e16+1, mid;
        while (l <= r)
        {
            mid = (l+r) >> 1;
            long long sl = calccnt(mid, i, k-i);
            if (sl >= m)
                r = mid-1;
            else
                l = mid+1;
        }
        long long sl = calccnt(mid, i, k - i), temp = 0;
        for (int j = 0; j <= 3; j++)
            temp += s[j][pos[j]];
        temp -= (sl-m)*mid;
        ans = min(ans, temp);
    }
    cout << ans;
}
