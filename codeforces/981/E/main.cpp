#include <bits/stdc++.h>
#define maxn 100004

using namespace std;


struct data
{
    int l, r, x;
} a[maxn];
int dp[maxn], n, ans = 0, q;

bool cmp(data x, data y)
{
    return x.r < y.r;
}

int main()

{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
        cin >> a[i].l >> a[i].r >> a[i].x;
    sort(a+1, a+n+1, cmp);
    for (int i = 1; i <= n; i++)
        {
            for (int j = n; j >= a[i].x; j--)
                if (dp[j-a[i].x] >= a[i].l)
                    dp[j] = max(dp[j], dp[j-a[i].x]);
            dp[a[i].x] = a[i].r;
        }
    for (int i = 1; i <= n; i++)
        if (dp[i])
            ans ++;
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        if (dp[i])
            cout << i << " ";
    return 0;
}

