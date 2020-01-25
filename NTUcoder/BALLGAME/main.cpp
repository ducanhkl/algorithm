#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 1000000007
#define maxn 1000000

using namespace std;

long long dp[maxn][1<<4], res = 0, ans = 1;
int m, n, k;

bool get_bit(int x,int y)
{
    return (x >> y)&1;
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
    memset(dp, 0, sizeof(dp));
    cin >> m >> n >> k;
    for (int i = 0; i < 4; i++)
        dp[0][1<<i] = 1;
    for (int i = 1; i < n; i++)
        for (int mask = 0; mask < (1<<4); mask++)
            if(__builtin_popcount(mask) <= i+1)
                for (int j = 0; j < 4; j ++)
                    if (get_bit(mask, j))
                    {
                        dp[i][mask] += dp[i-1][mask-(1<<j)]%maxnum;
                        if (__builtin_popcount(mask) < i+1)
                            dp[i][mask] += dp[i-1][mask]%maxnum;
                    }
    for (int i = 1; i < (1<<4); i++)
        if (__builtin_popcount(i)>=k)
            res += (dp[n-1][i])%maxnum;
    for (int i = 1; i <= m; i++)
    {
        ans *= res;
        ans = ans%maxnum;
    }
    cout << ans;
	return 0;
}

