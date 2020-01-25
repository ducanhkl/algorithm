#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5+100;
const long long mod = 1e9+7;

string s;
int n;
long long dp[maxn];
char a[maxn];
int cntu = 0, cntn = 0;
long long ans = 1;

void init()
{
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2])%mod;
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    init();
    for (int i = 1; i <= n; i++)
    {
        a[i] = s[i-1];
        if (a[i] == 'm' || a[i] == 'w')
            return cout << 0, 0;
        if (a[i] == 'u')
        {
            cntu++;
        } else
        {
            ans = (ans*dp[cntu])%mod;
            cntu = 0;
        }

        if (a[i] == 'n')
        {
            cntn ++;
        } else
        {
            ans = (ans * dp[cntn])%mod;
            cntn = 0;
        }
    }
    ans = (ans*dp[cntu])%mod;
    ans = (ans*dp[cntn])%mod;
    cout << ans;
    return 0;
}
