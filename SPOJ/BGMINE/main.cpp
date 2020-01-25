#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 1000006

using namespace std;

ll x[maxn], g[maxn], r[maxn], s[maxn], t[2*maxn], res = LONG_LONG_MIN, tree[maxn];
int n;

ll get(int x)
{
    ll ans = LONG_LONG_MAX;
    for(; x > 0; x -= (x&(-x)))
            if (tree[x] != -1)
                ans = min(ans, tree[x]);
    return ans;
}

void update(int x, ll y)
{
    for (; x < maxn; x += (x&(-x)))
        if ( tree[x] == -1)
            tree[x] = y;
        else tree[x] = min(tree[x], y);
}
int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < maxn; i++)
        tree[i] = -1;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> g[i] >> r[i], g[i] += g[i-1], r[i] += r[i-1];
    for (int i = 1; i <= n; i++)
        s[i] = r[i] - x[i];
    for (int i = n+1; i <= 2*n; i++)
        s[i] = r[i-n-1] - x[i-n];
    sort(s+1, s+2*n+1);
    for (int i = 1; i <= n; i++)
    {
        t[i] = lower_bound(s+1, s+2*n+1, r[i] - x[i])-s;
        t[i+n] = lower_bound(s+1, s+2*n+1, r[i-1] - x[i])-s;
    }
    update(lower_bound(s+1, s+2*n+1, 0)-s,0);
    for (int i = 1; i <= n; i++)
    {
        ll ans = get(t[i]);
        res = max(res, g[i]-g[i-1]);
        res = max(res, g[i] - ans);
        update(t[i+n], g[i]);
    }
    cout << res;
    return 0;
}
