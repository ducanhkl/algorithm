#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n, w, h;
struct data{
    int g, p, t, pos;
    pair <int, int> e;
} a[maxn], b[maxn];
pair <int, int> ans[maxn];

bool cmp1(data x, data y)
{
    if (x.p-x.t != y.p - y.t)
        return x.p-x.t < y.p - y.t;
    if (x.g != y.g)
        return x.g > y.g;
    if (x.g == 1)
        return x.p < y.p;
    else
        return x.p > y.p;
}

bool cmp2(data x, data y)
{
    if (x.g != y.g)
        return x.g < y.g;
    if (x.g == 1)
        return x.p < y.p;
    else
        return x.p > y.p;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> w >> h;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].g >> a[i].p >> a[i].t;
        a[i].pos = i;
        if (a[i].g == 1)
            a[i].e = {a[i].p, h};
        else
            a[i].e = {w, a[i].p};
    }
    sort(a+1, a+n+1, cmp1);
    for (int i = 1; i <= n; i++)
    {
        int last = i;
        while (last < n &&  a[last+1].p - a[last+1].t == a[i].p - a[i].t)
            last++;
        for (int j = i; j <= last; j++)
            b[j] = a[j];
        sort(b+i, b+last+1, cmp2);
        for (int j = i; j <= last; j++)
            ans[a[j].pos] = b[j].e;
        i = last;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i].first << " " << ans[i].second << endl;
}
