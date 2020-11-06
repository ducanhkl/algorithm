#include <bits/stdc++.h>

using namespace std;

const int maxn = 300;

struct point
{
    long long x;
    long long y;
} p[maxn];
int n;
long long dp[maxn][maxn];

long long area(point p1, point p2, point p3)
{
    return abs((p2.x-p1.x)*(p3.y-p1.y) - (p3.x-p1.x)*(p2.y - p1.y));
}

void solve1()
{
    long long res1 = 0;
    point p1 = p[1], p2 = p[2], p3 = p[3];
    while (true)
    {
        int flag = true;
        long long s = area(p1, p2, p3);
        for (int i = 1; i <= n; i++)
        {
            if (area(p[i], p2, p3) > s)
            {
                p1 = p[i];
                flag = false;
            }
            else if (area(p1, p[i], p3) > s)
            {
                p2 = p[i];
                flag = false;
            }
            else if (area(p1, p2, p[i]) > s)
            {
                p3 = p[i];
                flag = false;
            }
        }
        if (flag)
        {
            break;
        }
    }
    cout << fixed << setprecision(1) << (long double) (area(p1, p2, p3))/2 << endl;
}

void solve2()
{
    for (int len=2; len <= n; len ++)
    {
        for (int i = 1; i <= n-len; i++)
        {
            int j = i+len;
            dp[i][j] = LONG_LONG_MAX;
            for (int k = i+1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], max(dp[i][k], max(dp[k][j], area(p[i], p[k], p[j]))));
            }
        }
    }
    cout << fixed << setprecision(1) << (long double) (dp[1][n])/2 << endl;
}

int main()
{
    //freopen("inp.txt", "r" ,stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }
    solve1();
    solve2();
    return 0;
}
