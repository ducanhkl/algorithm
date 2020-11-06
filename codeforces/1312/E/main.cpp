#include <bits/stdc++.h>

using namespace std;

const int maxn = 600;

int n;
int a[maxn], dp[maxn], marr[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = i; j <= n; j++)
        {
            marr[++cnt] = a[j];
            while (cnt > 0 && marr[cnt] == marr[cnt-1])
            {
                cnt--;
                marr[cnt]++;
            }
            if (cnt == 1)
            {
                dp[j] = min(dp[j], dp[i-1] +1);
            }
        }
    }
    cout << dp[n];
    return 0;
}
