#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

long long n, colum[maxn], row[maxn], k;
struct data
{
    long long x, y, w, pos;
} a[maxn];

bool cmp(data x, data y)
{
    if (x.x == y.x)
        return x.y < y.y;
    return x.x < y.x;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].w;
        a[i].pos = i;
    }
    sort(a+1,a+n+1, cmp);
    int vt = 0;
    for (int i = 1; i <= n; i++)
        if (a[i].pos == 1)
    {
        vt = i;
        break;
    }
    row[a[vt].x] = a[vt].w;
    colum[a[vt].y] = a[vt].w;
    for (int i = vt + 1; i <= n; i++)
    {
        if (a[i].pos == n)
            {
                vt = i;
                break;
            }
        long long ss =0;
        int x = a[i].x, y = a[i].y, w = a[i].w;
        if (colum[y] >= k)
            ss = max(ss, colum[y] - k + w);
        if (row[x] >= k)
            ss = max(ss, row[x] - k + w);
        colum[y] = max(colum[y], ss);
        row[x] = max(row[x], ss);
    }
    long long ans = 0;
    if (colum[a[vt].y] >= k)
        ans = max(ans, colum[a[vt].y]-k+a[vt].w);
    if (row[a[vt].x] >= k)
        ans = max(ans, row[a[vt].x] - k + a[vt].w);
    cout << ans << endl;
    return 0;
}
