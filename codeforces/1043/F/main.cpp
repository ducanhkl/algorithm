#include <bits/stdc++.h>
#define maxc 300050
#define maxn 300050


using namespace std;

int n, cnt[maxc];
long long p[maxc], dp[30][maxc];
const long long mod = 1e9+7;

long long fast_pow(int x, int y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    long long res = fast_pow(x, y/2);
    res = (res*res)%mod;
    if (y%2)
        return res*x%mod;
    else
        return res;
}

long long C(int n, int k)
{
    if (k > n || (k==0 && n == 0))
        return 0;
    return  p[n]*fast_pow((p[n-k]*p[k]%mod), mod-2)%mod;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    memset(dp, 0, sizeof(dp));
    p[0] = 1;
    for (int i = 1; i < maxc; i++)
        p[i] = (p[i-1]*i)%mod;
    cin >> n;
    for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            cnt[x] ++;
        }
    for (int i = 1; i < maxc; i++)
        for (int j = 2*i; j < maxc; j += i)
            cnt[i] += cnt[j];
    for (int i = 1; i <= 20; i++)
    {
        for (int j = maxc-1; j >= 1; j--)
        {
            if (j == 5)
                n = n;
            dp[i][j] = C(cnt[j], i);
            for (int k = j*2; k < maxc; k += j)
                dp[i][j] = (dp[i][j]-dp[i][k]+mod)%mod;
        }
        if (dp[i][1] != 0)
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
