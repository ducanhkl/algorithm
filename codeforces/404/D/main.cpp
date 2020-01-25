#include <bits/stdc++.h>

using namespace std;

const long long maxn = 1e6+100, mod = 1e9+7;

long long dp[maxn][5];
string s;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> s;
    if (s[0] == '*')
        dp[0][4] = 1;
    if (s[0] == '1')
        dp[0][2] = 1;
    if (s[0] == '0')
        dp[0][0] = 1;
    if (s[0] == '?')
        dp[0][0] = dp[0][2] = dp[0][4] =  1;
    if (s[0] == '2' || s[s.length()-1] == '2')
        return cout << 0, 0;
    int n = s.length();
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '*' || s[i] == '?')
            dp[i][4] = (dp[i-1][2] + dp[i-1][4]+dp[i-1][3])%mod;
        if (s[i] == '0' || s[i] == '?')
            dp[i][0] = (dp[i-1][0] + dp[i-1][1])%mod;
        if (s[i] == '1' || s[i] == '?')
            dp[i][1] = (dp[i-1][4]), dp[i][2] = (dp[i-1][0]+dp[i-1][1])%mod;
        if (s[i] == '2' || s[i] == '?')
            dp[i][3] = (dp[i-1][4]);
    }
    cout << (dp[n-1][0] + dp[n-1][1] + dp[n-1][4])%mod;
    return 0;
}
