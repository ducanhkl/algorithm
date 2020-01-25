#include <bits/stdc++.h>
#define maxn 300000
#define maxm 1000010

using namespace std;

const long long mod = 1e9+7;
long long f[maxm], cnt[maxm], p[maxn], ans = 0;
int n, a[maxn];

int main()
{
    //freopen("inp.ttx", "r", stdin);
    ios_base::sync_with_stdio(false);
    memset(p, 0, sizeof(p));
    memset(cnt, 0, sizeof(cnt));
    p[0] = 1;
    for (int i = 1; i < maxn; i++)
        p[i] = p[i-1]*2LL%mod;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], cnt[a[i]]++;
    for (int i = maxm - 1; i >= 2; i--)
    {
        int counter = 0;
        for (int j = i; j < maxm; j+=i)
            counter += cnt[j];
        if (counter != 0)
        {
            f[i]  = counter*p[counter-1]%mod;
            for (int j = 2*i; j < maxm; j+=i)
                f[i] = (f[i] - f[j] + mod)%mod;
            ans = (ans + f[i]*i)%mod;
        }
    }
    cout << ans;
    return 0;
}
