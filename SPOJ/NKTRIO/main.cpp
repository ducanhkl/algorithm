#include <bits/stdc++.h>
#define maxn 1002

using namespace std;

int n;
int a[maxn][maxn], dp[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        a[i][0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        int j;
        for (j = 1; j <= i; j ++)
            if (a[i][dp[j]] == 1)
                break;
        for (int t = j+1; t < i; t++)
            if (a[i][dp[t]] == 0)
        {
            cout << i << " " << dp[j] << " " << dp[t];
            return 0;
        }
        for (int k = i; k > j; k--)
            dp[k] = dp[k-1];
        dp[j] = i;
    }
    cout << "-1 -1 -1";
}
