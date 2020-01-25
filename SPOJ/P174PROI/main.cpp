#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 5001

using namespace std;

ll dp[maxn][maxn];
int n, q;
string s;

int main()
{
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    memset(dp, 0, sizeof dp);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    for (int i = 0; i < n-1; i++)
        if (s[i] == s[i+1])
            dp[i][i+1] = 1;
    for (int j = 2; j <= n; j++)
        for (int i = 0; i < n; i++)
        {
            if (i+j >= n)
                break;
            int  k = i+j;
            if (s[i] == s[k])
                dp[i][k] = dp[i+1][k-1];
        }
    for (int j = 1; j <= n; j++)
        for (int i = 0; i < n; i++)
        {
            if (i+j >= n)
                break;
            int k = i+j;
            dp[i][k] += dp[i+1][k] + dp[i][k-1] - dp[i+1][k-1];
        }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << dp[x-1][y-1] << endl;
    }
    return 0;
}
