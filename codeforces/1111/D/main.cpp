#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
const long long mod = 1e9+7;
string s;
long long p[maxn], dp[maxn], dp1[maxn], dp2[maxn], cnt[maxn], ans[200][200];
int n;
long long m;

long long fast_pow(long long x, int y)
{
    if (y == 1)
        return x%mod;
    if (y == 0)
        return 1;
    long long res = fast_pow(x, y/2);
    res = res*res%mod;
    if (y%2)
        return res*x%mod;
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    p[0] = 1;
    for (int i = 1; i < maxn; i++)
        p[i] = p[i-1]*i%mod;
    cin >> s;
    n = s.length();
    s = " " + s;
    for (int i = 1; i <= n; i++)
        cnt[s[i]] ++;
    m = p[n/2];
    m = m*m%mod;
    for (int i = 'A'; i <= 'z'; i++)
        m = (m%mod*fast_pow(p[cnt[i]], mod-2))%mod;
    dp[0] = 1;
    for (int i = 'A'; i <= 'z'; i++)
        for (int j = n/2; j >= cnt[i]; j--)
            if (cnt[i] > 0)
                dp[j] = (dp[j]+dp[j-cnt[i]])%mod;
    for (int c = 'A'; c <= 'z'; c++)
    {
        for (int i = 0; i <= n/2; i++)
            dp1[i] = dp[i];
        for (int i = cnt[c]; i <= n/2; i++)
            dp1[i] = (dp1[i] - dp1[i-cnt[c]] + mod)%mod;
        ans[c][c] = m*2%mod*dp1[n/2]%mod;
        for (int ch = c+1; ch <= 'z'; ch++)
        {
            for (int i = 0; i <= n/2; i++)
                dp2[i] = dp1[i];
            for (int i = cnt[ch]; i <= n/2; i++)
                dp2[i] = (dp2[i]-dp2[i-cnt[ch]]+mod)%mod;
            ans[c][ch] = ans[ch][c] = m*2%mod*dp2[n/2]%mod;
        }
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << ans[s[x]][s[y]]  << endl;
    }
}
