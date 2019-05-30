#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+100;
int a[maxn][maxn], r[maxn][maxn], l[maxn][maxn], s[maxn];
int n, m, ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n >> m;
        ans = 0;
        memset(a, 0, sizeof(a));
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (a[i][j] != 0)
                    a[i][j] += a[i-1][j];
                else a[i][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            memset(s, 0, sizeof(s));
            int top = 0;
            for (int j = 1; j <= m; j++)
            {
                while (top != 0 && a[i][j] <= a[i][s[top]])
                    top--;
                if (top == 0)
                    l[i][j] = 0;
                else l[i][j] = s[top];
                s[++top] = j;
            }
            memset(s, 0, sizeof(s));
            top = 0;
            for (int j = m; j >= 1; j--)
            {
                while (top != 0 && a[i][j] <= a[i][s[top]])
                    top--;
                if (top == 0)
                    r[i][j] = m+1;
                else r[i][j] = s[top];
                s[++top] = j;
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                ans = max(ans, a[i][j]*(-(l[i][j]+1)+(r[i][j]-1)+1));
        cout << ans << endl;
    }
    return 0;
}
