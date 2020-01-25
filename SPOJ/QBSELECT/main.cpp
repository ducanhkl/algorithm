#include <bits/stdc++.h>

using namespace std;

const long long maxc = 1e18;
const int tt = 4, maxn = 1e4+100;
int n;
long long dp[maxn][300], a[maxn][tt];
vector <int> v;

long long calc(int pos, int status)
{
    long long res = 0;
    for (int i = 0; i < tt; i++)
        if ((status>>i)&1)
            res += a[pos][i];
    return res;
}

void reset()
{
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < (1<<tt); j++)
            dp[i][j] = -maxc;
}

void solve()
{
    long long ans = -maxc;
    reset();
    for (int i = 0; i < v.size(); i++)
        {
            int status = v[i];
            dp[1][status] = calc(1, status);
            ans = max(ans, calc(1, status));
        }
    for (int i = 2; i <= n; i++)
    {
        for (int pos = 0; pos < v.size(); pos ++)
            {
                int status = v[pos];
                for (int j = 0; j < (1<<tt); j++)
                    if ((j&status) == 0)
                        dp[i][status] = max(dp[i-1][j] + calc(i, status), dp[i][status]);
                ans = max(ans, dp[i][status]);
            }
    }
    cout << ans;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < (1<<tt); i++)
        if (((i>>1)&i) == 0)
            v.push_back(i);
    bool check = false;
    cin >> n;
    for (int j = 0; j < 4; j++)
        for (int i = 1; i <= n; i++)
                {
                    cin >> a[i][j];
                    if (a[i][j] >= 0)
                        check = true;
                }
    if (check == false)
    {
        long long mx = -maxc;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 4; j++)
                mx = max(a[i][j], mx);
        cout << mx;
        return 0;
    }
    solve();
    return 0;
}
