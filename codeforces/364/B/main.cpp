#include <bits/stdc++.h>

using namespace std;

const int maxc = 1e6+100;
int n, d,s  = 0;
int dp[maxc];

int main()
{
    memset(dp, 0, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin >> n >> d;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        s += x;
        for (int j = s; j >= x; j--)
            dp[j] = dp[j]|dp[j-x];
    }
    int ma = 0, now = 0, ans = 0;
    while (true)
    {
        ma += d;
        while (dp[ma] == 0)
            ma--;
        if (ma == now)
            break;
        now = ma, ans ++;
    }
    cout << now << " " << ans;
    return 0;
}
