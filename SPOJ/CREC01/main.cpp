#include <bits/stdc++.h>
#define maxn 1006

using namespace std;

int n, m;
long long a[maxn][maxn], dl[maxn][maxn], dr[maxn][maxn], l[maxn][maxn], r[maxn][maxn], s[maxn];
long long ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        char x;
        cin >> x;
        a[i][j] = (int)(x-'0');
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 0)
                a[i][j] = 0;
            else a[i][j] += a[i-1][j];
    for (int i = 1; i <= n; i++)
    {
        memset(s, 0, sizeof(s));
        int top = 0;
        for (int j = 1; j <= m; j++)
        {
            while(a[i][j] <= a[i][s[top]] && top != 0)
                top--;
            if (top == 0)
                l[i][j] = 0;
            else l[i][j] = s[top];
            dl[i][j] += (j-l[i][j])*a[i][j] + dl[i][s[top]];
            ans += dl[i][j];
            s[++top] = j;
        }
    }
    cout << ans;
    return 0;
}

