#include <bits/stdc++.h>

const int maxn = 2e5+100;

using namespace std;

long long x[maxn], g[maxn], r[maxn], s[maxn], t[2*maxn], res = 0, tree[maxn];
int n;

long long get(int x)
{
    long long ans = LONG_LONG_MAX;
    for(; x > 0; x -= (x&(-x)))
        ans = min(ans, tree[x]);
    return ans;
}

void update(int x, long long y)
{
    for (; x < maxn; x += (x&(-x)))
        tree[x] = min(tree[x], y);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < maxn; i++)
        tree[i] = LONG_LONG_MAX;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> g[i] >> r[i];
        g[i] += g[i-1];
        r[i] += r[i-1];
    }
    for (int i = 1; i <= n; i++)
    {
        s[i] = r[i] - x[i];
    }
    for (int i = n+1; i <= 2*n; i++)
    {
        s[i] = r[i-n-1] - x[i-n];
    }
    sort(s+1, s+2*n+1);
    for (int i = 1; i <= n; i++)
    {
        t[i] = lower_bound(s+1, s+2*n+1, r[i] - x[i])-s;
        t[i+n] = lower_bound(s+1, s+2*n+1, r[i-1] - x[i])-s;
    }
    for (int i = 1; i <= n; i++)
    {
        update(t[i+n], g[i-1]);
        long long ans = get(t[i]);
        res = max(res, g[i] - ans);
    }
    cout << res;
    return 0;
}
