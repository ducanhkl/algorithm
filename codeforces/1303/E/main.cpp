#include <bits/stdc++.h>

using namespace std;

const int maxn = 500;

string s, t;
int dp[maxn][maxn];

int n, m;

// dp[i][j] la so phan tu max nhat cua xau t khi duoc chia lam 2 phan
// tu vi tri pos  neu su dung i ky tu dau cua s va j ky tu dau cua t

bool solve(int pos)
{
    memset(dp, 0, sizeof(dp));
    dp[1][1] = pos;
    if (pos == 4)
    {
        pos ++;
        pos --;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= pos+1; j++)
        {
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if (s[i] == t[j])
            {
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);
            }
            if (s[i]  == t[dp[i][j]])
            {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + 1);
            }
        }
    }
    return dp[n+1][pos] > m;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> s >> t;
        n = s.length();
        m = t.length();
        s = " " + s + " ";
        t = " " + t + " ";
        int check = false;
        for (int i = 1; i <= m; i++)
        {
            if (solve(i))
            {
                check = true;
            }
        }
        if (check)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}
