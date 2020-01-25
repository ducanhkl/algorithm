#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair

using namespace std;

int n, dp[400][400];
int res = 0;
int main()
{
    memset(dp, 0, sizeof(dp));
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int t = s.length();
        int l = s[0] - 'a', r = s[t-1]-'a';
        for (int j = 0; j <= 40; j++)
            if (dp[j][l] > 0)
                dp[j][r] = max(dp[j][l] + t, dp[j][r]);
        dp[l][r] = max(dp[l][r], t);
    }
    for (int i = 0; i <= 40; i++)
        res = max(res, dp[i][i]);
    cout << res << endl;
    return 0;
}
