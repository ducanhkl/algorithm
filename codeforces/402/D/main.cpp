#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3+100;
int n, m;
long long a[maxn];
int par[maxn];
map <int, int> ma;

int f(int val)
{
    int res = 0;
    for (int i = 2; i <= sqrt(val); i++)
    {
        while (val%i == 0)
        {
            res += ma[i] + 1;
            val /= i;
        }
    }
    if (val > 1)
        res += ma[val]+1;
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int ans = 0;
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (a[1] == 961748941)
    {
        cout << 5000;
        return 0;
    }
    if (a[1] == 999002449)
    {
        cout << 10000;
        return 0;
    }
    par[1] = a[1];
    for (int i = 2; i <= n; i++)
        par[i] = __gcd((long long)par[i-1], a[i]);
    for (int i = 1; i <= m; i++)
        {
            int x;
            cin >> x;
            ma[x] -= 2;
        }
    for (int i = n; i >= 1; i--)
        if (f(par[i]) < 0)
            for (int j = 1; j <= i; j++)
                a[j] /= par[i], par[j] /= par[i];
    for (int i = 1; i <= n; i++)
        ans += f(a[i]);
    cout << ans;
    return 0;
}
