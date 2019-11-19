#include <bits/stdc++.h>

using namespace std;

const int maxn = 6000;
int n, m;
int in[maxn], l[maxn];

long long dis(int first, int second)
{
    if (second >= first)
        return second - first;
    return n-first+second;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (l[x] == 0)
            l[x] = y;
        else
        {
            if (dis(x, l[x]) >  dis(x, y))
                l[x] = y;
        }
        in[x] ++;
    }
    for (int i = 1; i <= n; i++)
    {
        long long  ans = 0;
        for (int j = 1; j <= n; j++)
        {
            if (in[j] == 0)
                continue;
            long long res = (long long)(in[j]-1)*n + dis(i, j) + dis(j, l[j]);
            ans = max(ans, res);
        }
        cout << ans << endl;
    }
}
