#include <bits/stdc++.h>
#define maxn 1000006
#define MOD 1000000009

using namespace std;

int n, k;
int a[maxn], b[maxn];
long long f[maxn], g[maxn];
long long tree[maxn], ans = 0;

long long get(int x)
{
    long long res = 0;
    for (; x < maxn; x += (x&(-x)))
        res = (res+tree[x])%MOD;
    return res;
}
void update(int x, long long y)
{
    for (; x > 0; x -= (x&(-x)))
        tree[x] = (tree[x]+y)%MOD;
    return;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], b[i] = a[i], f[i] = 1;
    sort(b+1, b+n+1);
    for (int j = 2; j <= k; j++)
    {
        memset(tree, 0, sizeof(tree));
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= n; i++)
        {
            int pos = lower_bound(b+1, b+n+1, a[i]) - b;
            g[i] = get(pos+1)%MOD;
            update(pos, f[i]);
        }
        swap(f, g);
    }
    for (int i = 1; i <= n; i++)
        ans = (ans+f[i])%MOD;
    cout << ans;
    return 0;
}
