#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

struct data
{
    int val, x, y, pos;
} p[maxn];
int n, m;
int tracex[maxn], tracey[maxn], root[maxn], ans[maxn], tmp[maxn], maxx[maxn], maxy[maxn];

int get_r(int u)
{
    if (root[u] == u)
        return u;
    return root[u] =get_r(root[u]);
}

bool cmp_by_val(data x, data y)
{
    return x.val < y.val;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        cin >> p[(i-1)*m+j].val;
        p[(i-1)*m+j].x = i;
        p[(i-1)*m+j].y = j;
        p[(i-1)*m+j].pos = (i-1)*m+j;
    }
    sort(p+1, p+n*m+1, cmp_by_val);
    for (int i = 1; i <= m*n; i++)
        root[i] = i;
    int j;
    for (int i = 1; i <= n*m; i = j)
    {
        j = i+1;
        while (p[j].val == p[i].val)
            j ++;
        if (i == 9)
            n = n;
        for (int k = i; k < j; k++)
        {
            int x = p[k].x;
            int y = p[k].y;
            if (!tracex[x])
                tracex[x] = k;
            else root[get_r(k)] = get_r(tracex[x]);
            if (!tracey[y])
                tracey[y] = k;
            else root[get_r(k)] = get_r(tracey[y]);
        }
        for (int k = i; k < j; k++)
        {
            int pos = get_r(k);
            tmp[pos] = max(tmp[pos], max(maxx[p[k].x], maxy[p[k].y])+1);
        }
        for (int k = i; k < j; k++)
            {
                tracex[p[k].x] = 0;
                tracey[p[k].y] = 0;
                maxx[p[k].x] = maxy[p[k].y] = ans[p[k].pos] = tmp[get_r(k)];
            }
    }
    for (int i = 1; i <= m*n; i++)
    {
        cout << ans[i] << " ";
        if (i%m == 0)
            cout << endl;
    }
    return 0;
}
