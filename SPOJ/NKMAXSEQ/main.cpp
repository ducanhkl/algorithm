#include <bits/stdc++.h>
#define maxn 500001

using namespace std;

int n, p, ans = 0, m = 0;
int tree[maxn], a[maxn], _a[maxn], b[maxn];

int get(int x)
{
    int res = INT_MAX;
    for (;x > 0; x -=(x&(-x)))
        res = min(res, tree[x]);
    return res;
}
void update(int x, int y)
{
    for (;x < maxn; x += (x&(-x)))
        tree[x] = min(tree[x], y);
    return;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> p;
    for (int i = 0; i < maxn; i++)
        tree[i] = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i-1];
        if (a[i] >= p)
            ans = i;
        _a[++m] = a[i];
        _a[++m] = a[i] - p;
    }
    sort(_a+1, _a+m+1);
    for (int i = 1; i <= n; i++)
        b[i] = lower_bound(_a+1, _a+m+1, a[i])-_a;
    for (int i = 1; i <= n; i++)
    {
        int vt = lower_bound(_a+1, _a+m+1, a[i] - p)- _a;
        int k = get(vt);
        if (k != INT_MAX && a[i] - a[k] >= p)
            ans = max(ans, i-k);
        update(b[i], i);
    }
    if (ans == 0)
        return cout << -1, 0;
    cout << ans;
    return 0;
}
