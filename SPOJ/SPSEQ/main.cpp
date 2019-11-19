#include <bits/stdc++.h>
#define maxn 100009

using namespace std;

int a[maxn], b[maxn], tree[maxn], f1[maxn], f2[maxn];
int n, ans = 0;


int get(int x)
{
    int res = 0;
    for(; x > 0; x -= (x&(-x)))
        res = max(tree[x], res);
    return res;
}

void update(int x, int y)
{
    for (; x < maxn; x += (x&(-x)))
        tree[x] = max(tree[x], y);
    return;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i];
    sort(b+1, b+n+1);
    memset(tree, 0, sizeof(tree));
    memset(f1, 0, sizeof(f1));
    memset(f2, 0, sizeof(f2));
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(b+1, b+n+1, a[i])-b;
        f1[i] = get(pos-1)+1;
        update(pos, f1[i]);
    }
    memset(tree, 0, sizeof(tree));
    for (int i = n; i >= 1; i--)
    {
        int pos = lower_bound(b+1, b+n+1, a[i])-b;
        f2[i] = get(pos-1)+1;
        update(pos, f2[i]);
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, 2*min(f1[i], f2[i])-1);
    cout << ans;
    return 0;
}
