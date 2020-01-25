#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

long long sl[maxn], cnt = 0, dd[maxn], n, q, a[maxn], ans = 0;
vector<int> p[maxn];

void prime_factor(int x)
{
    int _x = x;
    for (int i = 2; i <= sqrt(x); i++)
        if (x%i == 0)
        {
            p[_x].push_back(i);
            while (x%i==0)
                x /= i;
        }
    if (x > 1)
        p[_x].push_back(x);
}

void update(int x, int y)
{
    if(p[x].size() == 0)
        return;
    for (int i = 1; i < (1<<p[x].size()); i++)
    {
        int s = 1;
        for (int j = 0; j < p[x].size(); j++)
            if ((i>>j)&1)
                s *= p[x][j];
        sl[s] += y;
    }
}

long long get(int x)
{
    if (p[x].size() == 0)
        return 0;
    int res = 0;
    for (int i = 1; i < (1<<p[x].size()); i++)
    {
        int s = 1, m = __builtin_popcount(i);
        for (int j = 0; j < p[x].size(); j++)
            if ((i>>j)&1)
                s *= p[x][j];
        if (m%2)
            res += sl[s];
        else
            res -= sl[s];
    }
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dd, 0, sizeof(dd));
    memset(sl, 0, sizeof(sl));
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (p[a[i]].size() == 0)
                prime_factor(a[i]);
        }
    for (int i = 1; i <= q; i++)
    {
        int x;
        cin >> x;
        if (dd[x])
        {
            cnt --;
            update(a[x], -1);
            ans -= cnt-get(a[x]);
        }
        else
        {
            ans += cnt-get(a[x]);
            update(a[x], 1);
            cnt++;
        }
        dd[x] ^= 1;
        cout << ans << endl;
    }
    return 0;
}
