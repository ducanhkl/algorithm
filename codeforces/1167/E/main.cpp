#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000;
int n;
long long x, res, ans = 0;
int l[maxn], r[maxn], a[maxn], ma[maxn];

int main()
{
    //freopen("inp.txt","r", stdin);
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    memset(ma, 0, sizeof(ma));
    ios_base::sync_with_stdio(false);
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (l[a[i]] == 0)
            l[a[i]] = i;
        r[a[i]] = i;
    }
    for (int i = 1; i <= x; i++)
        ma[i] = max(ma[i-1], r[i]);
    res = x;
    for (int i = 1; i <= x; i++)
        if (l[i] != 0 && ma[i-1] > l[i])
    {
        res = i;
        break;
    }
    for (int i = x; i >= 1; i--)
    {
        while (res > i || ma[res-1] > n)
            res--;
        ans += res;
        if (r[i] > n)
            break;
        if (l[i])
            n = min(n, l[i]);
    }
    cout << ans;
    return 0;
}
