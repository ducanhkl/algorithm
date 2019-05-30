#include <bits/stdc++.h>

using namespace std;

long long ans = 1, n;
int k;
const long long mod = 1e9+7;
vector <pair<long long, int> > v;
long long inv[200];

long long fast_pow(long long x, int y)
{
    if (y == 1)
        return x%mod;
    if (y == 0)
        return 1;
    long long res = fast_pow(x, y/2);
    if (y%2)
        return (((res*res)%mod)*x)%mod;
    return res*res%mod;
}

void pri(long long n)
{
    int i = 2;
    for (; i <= sqrt(n); i++)
        if (n%i == 0)
    {
        pair <long long, int> x;
        x.first = i;
        while (n%i == 0)
            x.second++, n /= i;
        v.push_back(x);
    }
    if (n != 1)
        v.push_back({n, 1});
    return ;
}

long long calc(long long x, int t)
{
    long long dp[t+100];
    x = x%mod;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= t; i++)
        dp[i] = (dp[i-1]*x)%mod;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= t; j++)
            dp[j] = (dp[j-1]+dp[j])%mod;
        for (int j = 0; j <= t; j++)
            dp[j] = (dp[j]*inv[j+1])%mod;
    }
    return dp[t];
}


int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= 100; i++)
        inv[i] = fast_pow(i, mod-2);
    pri(n);
    for (int i = 0; i < v.size(); i++)
        ans = (ans*calc(v[i].first, v[i].second))%mod;
    cout << ans;
    return 0;
}
