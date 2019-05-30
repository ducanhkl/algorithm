#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n, ans = 0;
int a[maxn], uc[maxn];


void solve()
{
    ans = 0;
    int x = a[1];
    for (int i = 2; i <= n; i++)
        x = __gcd(x, a[i]);
    if (x > 1)
        return cout << "YES " << 0 << endl, (void)0;
    for (int i = 2; i <= n; i++)
        if (a[i-1]%2 && a[i]%2)
    {
            ans ++;
            int s = a[i] + a[i-1];
            int t = a[i] - a[i-1];
            a[i] = s;
            a[i-1] = t;
    }
    for (int i = 1; i <= n; i++)
        if (a[i]%2)
            ans += 2;
    cout << "YES " <<  ans << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test --)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (n == 1 && a[1] == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        solve();
    }
    return 0;
}
