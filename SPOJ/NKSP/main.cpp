#include <bits/stdc++.h>


using namespace std;


const int maxn = 1e3+100;

string s;
int a[maxn];
bool f[maxn][maxn], dd[maxn][maxn];
long long dp[maxn], ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(f, 0, sizeof(f));
    memset(dp, 0, sizeof(dp));
    memset(dd, 0, sizeof(dd));
    ios_base::sync_with_stdio(false);
    cin >> s;
    int n = s.length();
    for (int i = 0; i <= n; i++)
        a[i] = s[i-1] - 'a';
    for (int i = 1; i < n; i++)
        if (a[i] == a[i+1])
            f[i][i+1] = 1;
    for (int i = 1; i <= n; i++)
        f[i][i] = 1;
    for (int i = 1; i <= n; i++)
    {
        int len = 0;
        while (i-len >= 1 && i+len <= n && a[i-len] == a[i+len])
        {
            f[i-len][i+len] = 1;
            len++;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        int l = i-1, r = i;
        while (l >= 1 && r <= n && a[l] == a[r])
        {
            f[l][r] = 1;
            l--, r++;
        }
    }
    /*for (int j = 2;  j < n; j++)
        for (int i = 1; i <= n-j; i++)
            if (a[i] == a[i+j])
                f[i][i+j] = f[i+1][i+j-1];
            else f[i][i+j] = 0;*/
    for (int i = 1; i <= n; i++)
        for (int j = i-1; j >= 1; j--)
            {
                if (f[j][i] == 1 && dd[i][j] == 0)
                    dp[i] += dp[j-1]+1;
            }
    for (int i = 1; i <= n; i++)
        ans += dp[i];
    cout << ans;
    return 0;
}
