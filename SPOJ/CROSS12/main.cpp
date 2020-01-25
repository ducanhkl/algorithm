#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, m;
int cache[maxn], f[maxn], a[maxn], t[maxn], r[maxn];

int calc(int x)
{
    int i = 0, res = 0;
    while (i + x <= m)
    {
        res ++;
        i += x;
        while (a[i] == 1)
            i--;
    }
    return res+1;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    memset(a, 0, sizeof(a));
    memset(cache, 0, sizeof(cache));
    for (int i = 1; i <= m; i++)
    {
        char x;
        cin >> x;
        a[i] = x-'0';
    }
    for (int i = 1; i <= n; i++)
    {
        if (cache[r[i]] != 0)
            t[i] = cache[r[i]];
        else t[i] = cache[r[i]] = calc(r[i]);
    }
    sort(t+1, t+n+1);
    f[1] = t[1];
    f[2] = t[2];
    for (int i = 3; i <= n; i++)
        f[i] = min(f[i-1] + t[1] + t[i], f[i-2] + t[1] + 2*t[2] + t[i]);
    cout << f[n];
    return 0;
}
