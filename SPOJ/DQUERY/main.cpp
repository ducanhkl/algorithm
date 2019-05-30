#include <bits/stdc++.h>

using namespace std;


struct query
{
    int l, r, pos;
};

query b[200001];
int res[200001];
int a[300000], n, q, ans = 0;
int sl[1000006];


bool cmpbymo(query x, query y)
{
    int s = sqrt(n);
    if (x.l/s != y.l/s)
        return x.l/s < y.l/s;
    else return x.r < y.r;
}

bool cmpbypos(query x, query y)
{
    return x.pos < y.pos;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a+i);
    cin >> q;
    for (int i = 1; i <= q; i++)
        scanf("%d", &b[i].l), scanf("%d", &b[i].r), b[i].pos = i;
    sort(b+1, b+q+1, cmpbymo);
    for (int i = b[1].l; i <= b[1].r; i++)
    {
        if (sl[a[i]] == 0)
            ans ++;
        sl[a[i]] ++;
    }
    res[b[1].pos] = ans;
    for (int i = 2; i <= q; i++)
    {
        for (int j = b[i-1].l; j < b[i].l; j++)
        {
            sl[a[j]] --;
            if (sl[a[j]] == 0)
                ans--;
        }
        for (int j = b[i-1].l-1; j >= b[i].l; j--)
        {
            if (sl[a[j]] == 0)
                ans++;
            sl[a[j]] ++;
        }
        for (int j = b[i-1].r; j > b[i].r; j--)
        {
            sl[a[j]] --;
            if (sl[a[j]] == 0)
                ans--;
        }
        for (int j = b[i-1].r+1; j <= b[i].r; j++)
        {
            if (sl[a[j]] == 0)
                ans++;
            sl[a[j]] ++;
        }
        res[b[i].pos] = ans;
    }
    for (int i = 1; i <= q; i++)
        printf("%d\n",res[i]);
    return 0;
}
