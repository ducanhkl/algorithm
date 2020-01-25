#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 100004

using namespace std;

ll a[maxn], dp[100000][20];
int n, m;
ll res = 0LL;

int offbit(int x, int y)
{
    return x^(1<<y);
}

bool check (int x, int y)
{
    return abs(x-y)>m;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= 1<<n+1; i++)
    {
        if (i == 11)
            n = n;
        int t[20], dem = 0;
        memset(t, 0, sizeof(t));
        for (int j = 0; j < n; j++)
            if ((i>>j)&1)
                t[++dem] = j;
        if (dem == 1)
            {
                dp[i][t[dem]+1] = 1;
                continue;
            }
        for (int j = 1; j <= dem; j++)
            for (int k = 1; k <= dem; k++)
                if (k!=j)
        {
            int ii = offbit(i, t[j]);
            if (check(a[t[j]+1], a[t[k]+1]))
                dp[i][t[j]+1] += dp[ii][t[k]+1];
        }
    }
    int t = (1<<n)-1;
    for (int i = 1; i <= n; i++)
        res += dp[t][i];
    cout << res;
    return 0;
}
