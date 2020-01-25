#include "bits/stdc++.h"

using namespace std;

const int maxn = 2e5+100;

int n, m;
int a[maxn], par[maxn][20];
int h[maxn];


void input()
{
    for (int i = 1; i <= n; i++)
        h[i] = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], par[i][0] = a[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int p, s;
        cin >> p >> s;
        h[s] = max(h[s], p);
    }
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j+(1 << i)-1 <= n; j++)
            par[j][i] = max(par[j][i-1], par[j+(1<<(i-1))][i-1]);
    for (int i = n; i >= 1; i--)
        h[i] = max(h[i], h[i+1]);
}

int getmax(int l, int r)
{
    int p2 = log2(r-l+1);
    return max(par[l][p2], par[r-(1<<p2)+1][p2]);
}

int get(int pos)
{
    int l = 1, r = pos;
    int res = -1;
    while (l <= r)
    {
        int mid = (l+r)>>1;
        int val = getmax(pos-mid+1, pos);
        if (val <= h[mid])
        {
            res = mid;
            l = mid+1;
        } else
            r = mid-1;
    }
    return  res;
}

void solve()
{
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        int len = get(i);
        if(len == -1)
        {
            cout << -1 << endl;
            return;
        }
        i = i - len + 1;
        ans ++;
    }
    cout << ans << endl;
}

int main ()
{
   //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while  (test--)
    {
        input();
        solve();
    }
}