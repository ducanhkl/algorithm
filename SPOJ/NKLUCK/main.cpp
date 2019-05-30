#include <bits/stdc++.h>
#define maxn 500050

using namespace std;


long long tree[maxn];
long long a[maxn], n, c;
int d1[maxn], d2[maxn], b[maxn];

long long get(int x)
{
    long long res = 0;
    for (; x > 0; x -= (x&-x))
        res += tree[x];
    return res;
}

void update (int x)
{
    for (; x < maxn; x += (x&(-x)))
        tree[x] ++;
    return;
}
long long calc(int x, int *d)
{
    memset(tree, 0, sizeof(tree));
    memset(d, 0, sizeof(d));
    memset(b, 0, sizeof(b));
    long long res = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] >= x)
            d[i] = 1;
        else d[i] = -1;
    for (int i = 1; i <= n; i++)
        d[i] += d[i-1];
    for (int i = 0; i <= n; i++)
        b[i] = d[i];
    sort(b, b+n+1);
    for (int i = 0; i <= n; i++)
        d[i] = lower_bound(b, b+n+1, d[i])-b+1;
    for (int i = 0; i <= n; i++)
        {
            res += get(d[i]);
            update(d[i]);
        }
    return res;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long x1 = calc(c, d1);
    long long x2 = calc(c+1, d2);
    long double res = x1-x2;
    cout << fixed << setprecision(7) << res/((long double)(n*(n+1)/2));
    return 0;
}
