#include <iostream>

using namespace std;

const int maxn = 1e5+100;

struct point
{
    int x, y;
} p[200];

int n, m;
int dp[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1 ; i <= n; i++)
    {
        int x, s;
        cin >> x >> s;
        p[i].x = x-s;
        p[i].y = x+s;
    }
    for (int i = 1; i <= m; i++)
    {
        dp[i] = i;
        for (int j = 1; j <= n; j++)
        {
            if (p[j].x <= i && i <= p[j].y)
            {
                dp[i] = min(dp[i], dp[max(0, p[j].x-1)]);
            } else
            {
                if (i > p[j].y)
                {
                    dp[i] = min(dp[i], dp[max(0, p[j].x - (i - p[j].y) - 1)]+(i - p[j].y));
                }
            }
        }
    }
    cout << dp[m];
    return 0;
}