#include <bits/stdc++.h>
#define maxn 1000004

using namespace std;

int n;
long long a[maxn], dp[maxn][3], ans, aa, b;
vector <long long> p;
const long long MAXC = 1234567890101112;

void push(long long x)
{
    int d = 2;
    while (d <= sqrt(x))
    {
        if (x%d == 0)
            p.push_back(d), x /= d;
        d++;
    }
    if (x != 1)
        p.push_back(x);
}

void check(long long x)
{
    memset(dp, 0, sizeof(dp));
    dp[0][1] = MAXC;
    dp[0][2] = MAXC;
    for (int i = 1; i <= n; i++)
        if (a[i]%x)
    {
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + aa;
        if ((a[i]+1)%x && (a[i]-1)%x)
            dp[i][0] = dp[i][2] = MAXC;
        else
        {
            dp[i][0] = dp[i-1][0] + b;
            dp[i][2] = min(dp[i-1][1], dp[i-1][2]) + b;
        }
    } else
    {
        dp[i][0] = dp[i-1][0];
        dp[i][2] = min(dp[i-1][2], dp[i-1][1]);
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + aa;
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> aa >> b;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    push(a[1]), push(a[1]-1), push(a[1]+1);
    push(a[n]), push(a[n]-1), push(a[n]+1);
    sort(p.begin(), p.end());
    check(p[1]);
    ans = min(dp[n][0], min(dp[n][1], dp[n][2]));
    for (int i = 1; i < p.size(); i++)
        if (p[i] != p[i-1])
        {
            check(p[i]);
            ans = min(ans, min(dp[n][0], min(dp[n][1], dp[n][2])));
        }
    cout << ans;
    return 0;
}
