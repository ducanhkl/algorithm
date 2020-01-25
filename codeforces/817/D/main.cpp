#include <bits/stdc++.h>

using namespace std;

const long long maxn = 1e6+100;
int n;
long long a[maxn], r[maxn], l[maxn], ans = 0;

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        l[i] = i-1;
        while (l[i] > 0 && a[i] >= a[l[i]])
            l[i] = l[l[i]];
    }
    for (int i = n; i >= 1; i--)
    {
        r[i] = i+1;
        while (r[i] <= n && a[i] > a[r[i]])
            r[i] = r[r[i]];
    }
    for (int i = 1; i <= n; i++)
        ans += (i-l[i])*(r[i] - i)*a[i];
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    solve();
    for (int i = 1; i <= n; i++)
        a[i] = -a[i];
    solve();
    cout << ans;
    return 0;
}
