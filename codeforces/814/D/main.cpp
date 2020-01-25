#include <bits/stdc++.h>
#define maxn 1006

using namespace std;

struct circle
{
    long double x, y, r;
};

const long double PI = 3.14159265359;
int n;
long double ans = 0, dp[maxn][3][3];
circle a[maxn];
int ufr[maxn];
vector <int> e[maxn];

bool cmp(circle x, circle y)
{
    return x.r > y.r;
}

long double dis(circle x, circle y)
{
    long double aa = (y.x-x.x)*(y.x-x.x);
    long double bb = (y.y-x.y)*(y.y-x.y);
    return sqrt(aa+bb);
}

bool checkarea(circle x, circle y)
{
    return dis(x, y) < x.r+y.r;
}

long double area(circle x)
{
    return x.r*x.r;
}

void dfs(int u)
{
    ufr[u] = 1;
    long double s = area(a[u]);
//    memset(g, 0, sizeof(g));
    dp[u][1][1] = dp[u][1][0] = area(a[u]);
    dp[u][0][0] = dp[u][0][1] = -area(a[u]);
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        dfs(v);
        dp[u][1][0] += max(dp[v][0][0], dp[v][1][1]);
        dp[u][1][1] += dp[v][0][1];
        dp[u][0][0] += dp[v][1][0];
        dp[u][0][1] += max(dp[v][1][1], dp[v][0][0]);
    }

    return ;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    memset(ufr, 0, sizeof(ufr));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y >> a[i].r;
    sort(a+1, a+n+1, cmp);
    for (int i = 1; i <= n; i++)
        for (int j = i-1; j >= 1; j--)
    {
        if (checkarea(a[i], a[j]))
            {
                e[j].push_back(i);
                break;
            }
    }
    for (int i = 1; i <= n; i++)
        if (ufr[i] == 0)
    {
        dfs(i);
        ans += dp[i][1][0];
    }
    cout <<fixed << setprecision(12) << ans*PI;
    return 0;
}
