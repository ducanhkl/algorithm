#include <bits/stdc++.h>
#define maxn 100

using namespace std;

int n;
char a[maxn];
int num[100][100], dp[maxn][(1<<20)+100], ans = 0;
const int mod = 1e9+7;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] -= '0';
    for (int i = 1; i <= n; i++)
    {
        for (int j = i, k = 0; j <= n; j++)
        {
            k = k*2+a[j];
            if (k > 20)
                break;
            num[i][j] = k;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
        for (int tt = 0; tt < (1<<20); tt++)
            if (dp[i][tt] != 0)
        {
            for (int j = i; j <= n; j++)
            {
                int s = num[i][j];
                if (s != 0)
                    dp[j+1][tt|(1<<(s-1))] = (dp[i][tt] + dp[j+1][tt|(1<<(s-1))])%mod;
            }
        }
    }
    for (int i = 1; i <= n+1; i++)
        for (int j = 1; j <= 20; j++)
            ans = (ans + dp[i][(1<<j)-1])%mod;
    cout << ans;
    return 0;
}
