#include "bits/stdc++.h"

using namespace std;


const  int maxn = 1e5+100;

struct line
{
    long long x, y;
};

vector <line> v[20];
int rg[20];
int n, k;
long long sum[maxn], s[maxn], a[maxn], dp[maxn][20];

bool check(line d1, line d2, line d3)
{
    return  (d3.y-d1.y)*(d1.x-d2.x)<(d2.y-d1.y)*(d1.x-d3.x);
}

void add(int len, line d)
{
    vector <line> &ve = v[len];
    while (ve.size() > 1 && check(ve[ve.size()-2], ve[ve.size()-1], d))
        ve.pop_back();
    ve.push_back(d);
}

long long get(int len, int x)
{
    vector <line> &ve = v[len];
    rg[len] = min(rg[len], (int)ve.size()-1);
    while (rg[len] < ve.size()-1 && ve[rg[len]].x*x+ve[rg[len]].y > ve[rg[len]+1].x*x + ve[rg[len]+1].y)
        rg[len] ++;
    return  ve[rg[len]].x*x + ve[rg[len]].y;
}

int main ()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    reverse(a+1, a+n+1);
    add(0, {0, 0});
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i-1] + a[i];
        s[i] = s[i-1] + sum[i];
    }
    for (int i = 1; i <= n; i++)
    {
        // dp[i][j] = min(dp[x][j] + s[i-1] - s[x] - sum[x]*(i-x-1)) = sum[i-1] + min(-sum[x]*i + dp[x][j]+sum[x]*(x+1) - s[x])
        for (int j = 1; j <= k; j++)
        {
            if (j > i)
                break;
            long long val = get(j-1, i);
            dp[i][j] = s[i-1] + val;
            add(j, {-sum[i], dp[i][j] - s[i] + sum[i]*(i+1)});
        }
    }
    cout << dp[n][k];
}