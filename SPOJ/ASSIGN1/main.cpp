#include <bits/stdc++.h>
#define maxn 500

using namespace std;

int d[maxn],par[maxn], chil[maxn], a[maxn][maxn];
int n, l = INT_MAX, r = INT_MIN;
int last, ans = -1;

bool findpath(int x)
{
    memset(d, 0, sizeof(d));
    queue <int> q;
    for (int i = 1; i <= n; i++)
        if (chil[i] == 0)
            q.push(i);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
            if (!d[i] && a[u][i] <= x)
        {
            d[i] = u;
            if (par[i] == 0)
            {
                last = i;
                return true;
            }
            q.push(par[i]);
        }
    }
    return false;
}

void incflow()
{
    while (last)
    {
        int x = d[last],  y = last;
        last = chil[x], chil[x] = y, par[y] = x;
    }
}

bool check(int x)
{
    int res = 0;
    memset(par, 0, sizeof(par));
    memset(chil, 0, sizeof(chil));
    last = 0;
    while (findpath(x))
        incflow();
    for (int i = 1; i <= n; i++)
        res += (int)(chil[i] != 0);
    return res == n;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            l = min(l, a[i][j]);
            r = max(r, a[i][j]);
        }
    }
    while (l <= r)
    {
        int mid = (l+r)>>1;
        if (check(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    cout << ans;
    return 0;
}
