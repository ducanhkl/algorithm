#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;
int m, n;
long long a[maxn], ans, ansd, b[maxn];
bool dd[maxn];

long long fast_pow(long long x, int y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    long long res = fast_pow(x, y/2);
    res = (res*res)%m;
    if (y%2)
        return (res*x)%m;
    else
        return res;
}

bool solve(long long *arr, int n)
{
    if (n == 1)
    {
        ans = arr[1];
        ansd = 1;
        return 1;
    }
    memset(dd, 0, sizeof(dd));
    long long sd = arr[2] - arr[1];
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        cnt += binary_search(arr+1, arr+n+1, (arr[i]+sd)%m);
    int k = n-cnt;
    long long d = sd*fast_pow(k, m-2)%m;
    ans = -1, ansd = d;
    for (int i = 1; i <= n; i++)
    {
        long long val = (arr[i]+d)%m;
        int pos = lower_bound(arr+1, arr+n+1, val)-arr;
        if (arr[pos] != val)
            continue;
        if (dd[pos] == 1)
            return -1;
        dd[pos] = 1;
    }
    for (int i = 1; i <= n; i++)
        if (dd[i] == 0)
            if (ans == -1)
                ans = arr[i];
            else
                return 0;
    return 1;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    if (n == 1)
        return cout << a[1] << " 0", 0;
    if (n == m)
        return cout << "0 1", 0;
    if (2*n >= m)
    {
        int cnt = 0;
        for (int i = 0; i < m; i++)
            if (!binary_search(a+1, a+n+1, i))
                b[++cnt] = i;
        if (!solve(b, m-n))
            return cout << -1, 0;
        ans = (ans+(m-n)*ansd)%m;
        cout << ans << " " << ansd;
        return 0;
    }
    if (!solve(a, n))
        return cout << -1, 0;
    cout << ans << " " << ansd;
    return 0;
}
