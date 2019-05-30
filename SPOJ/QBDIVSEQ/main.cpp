#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int b[maxn], a[maxn], tree[maxn], f[maxn];
int n, ans = 0;
int get(int x)
{
    int res = 0;
    for (;x < maxn;x+=(x&(-x)))
        res = max(res, tree[x]);
    return res;
}

void update(int x, int y)
{
    for (; x > 0; x -= (x&(-x)))
        tree[x] = max(tree[x], y);
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(tree, 0, sizeof(tree));
    memset(f, 0, sizeof(f));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];
    sort(b+1, b+n+1);
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(b+1, b+n+1, a[i])-b;
        f[i] = get(pos+1) + 1;
        update(pos, f[i]);
        ans = max(ans, f[i]);
    }
    cout << ans;
    return 0;
}
