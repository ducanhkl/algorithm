#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3+100;
int n, a, b;
long long dp[maxn], l[maxn][maxn];
char arr[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    memset(l, 0, sizeof(l));
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i-1] + a;
            for (int j = 1; j < i; j++)
            {
                if (arr[i] == arr[j])
                    l[j][i] = 1 + l[j-1][i-1];
                else
                    l[j][i] = 0;
                int len = min(i*1LL-j, l[j][i]);
                dp[i] = min(dp[i], dp[i-len] + b);
            }
        }
    cout << dp[n];
    return 0;
}
