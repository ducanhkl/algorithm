#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

int ans[maxn], a[maxn], n = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    char x;
    while (cin >> x)
        a[++n] = x-'0';
    int f = 1, s = n, l = 0, r = 0;
    if (a[1] == 1 && a[n] != 1)
        f++, l = 1;
    for (; f <= s; f++, s--)
    {
        a[f] += l*10;
        a[s] -= r;
        if (a[f] - a[s] > 9)
            r = 1, a[s] += 10;
        else
            r = 0;
        if (a[f] - a[s] > 0)
            a[f] --, l = 1;
        else
            l = 0;
        if (a[f] > 18 || a[f] != a[s])
            return cout << 0, 0;
        ans[f] = (a[f]+1)/2;
        ans[s] = a[s]/2;
        if (ans[f] + ans[s] != a[f])
            return cout << 0, 0;
    }
    if (l != r)
        return cout << 0, 0;
    if (a[1] == 1 && a[n] != 1)
    {
        for (int i = 2; i <= n; i++)
            cout << ans[i];
    } else
    {
        for (int i = 1; i <= n; i++)
            cout << ans[i];
    }
    return 0;
}
