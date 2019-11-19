#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 10005
#define MOD 5000000

using namespace std;

ll a[maxn], dp[55][100001], ans = 0;
int n, k;
ll tree[100001];

ll get(int x)
{
    ll res = 0;
    for (; x > 0; x -= (x&(-x)))
        res = (res + tree[x])%MOD;
    return res;
}

void update(int x,ll y)
{
    for (; x < 100001; x += (x&(-x)))
        tree[x] = (tree[x] + y)%MOD;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> k;
    bool check = true;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            check = true;
        dp[1][i] ++;
    }
    if (check)
        for (int i = 1; i <=n; i++)
            a[i] ++;
    for (int i = 2; i <= k; i++)
        {
            memset(tree, 0, sizeof(tree));
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = get(a[j] - 1);
                update(a[j], dp[i-1][j]);
            }
        }
    for (int i = 1; i <= n; i++)
        ans = (ans + dp[k][i]) % MOD;
    cout << ans;
    return 0;
}
