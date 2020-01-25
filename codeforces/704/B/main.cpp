#include <bits/stdc++.h>
#define maxn 6000
using namespace std;

int n, s, e, sl;
long long x[maxn], a[maxn], b[maxn], c[maxn], d[maxn], ans[maxn], dd;

long long dis(int u, int v)
{
    if (u < v)
        return x[v]-x[u]+d[u]+a[v];
    else
        return x[u]-x[v]+c[u]+b[v];
}

void push(int x, int i)
{
    sl ++;
    for (int i = sl; i > x; i--)
        ans[i] = ans[i-1];
    ans[x+1] = i;
    return;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> s >> e;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) cin >> d[i];
    ans[1] = s, ans[2] = e;
    sl = 2;
    dd = dis(s, e);
    for (int i = 1; i <= n; i++)
    {
        if (i == s || i == e)
            continue;
        long long t = LONG_MAX, pos = -1;
        for (int j = 1; j < sl; j++)
        {
            long long res = dd - dis(ans[j], ans[j+1]) + dis(ans[j], i) + dis(i, ans[j+1]);
            if (t == LONG_MAX || res < t)
            {
                t = res;
                pos = j;
            }
        }
        dd = t;
        push(pos, i);
    }
    cout << dd;
    return 0;
}
