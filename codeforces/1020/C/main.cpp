#include <bits/stdc++.h>
#define maxn 4000

using namespace std;

struct data
{
    long long p, c;
} a[maxn];
bool cmp(data x, data y)
{
    return x.c < y.c;
}

int n, m, cnt[maxn], g[maxn];
long long ans = LONG_LONG_MAX;

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(cnt, 0, sizeof(cnt));
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].p >> a[i].c;
        cnt[a[i].p] ++;
    }
    sort(a+1, a+n+1, cmp);
    for (int i = cnt[1]; i <= n; i++)
    {
        memset(g, 0, sizeof(g));
        long long res = 0, sl = 0;
        for (int j = 2; j <= m; j++)
            if (cnt[j] >= i)
                g[j] += cnt[j]-i+1, sl += g[j];
        if (sl > i-cnt[1])
            continue;
        sl = i-cnt[1]-sl;
        for (int j = 1; j <= n; j++)
            if (g[a[j].p])
                g[a[j].p] --, res += a[j].c;
            else
                if (a[j].p != 1 && sl > 0)
                    sl--, res += a[j].c;
        ans = min(ans, res);
    }
    cout << ans;
    return 0;
}
