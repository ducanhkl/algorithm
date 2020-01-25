#include <bits/stdc++.h>

using namespace std;


const int maxn = 1030, maxc = 1e6+100;
int kmp[maxn], dp[maxn][70][70], next_t[maxn][50], next_s[maxn][50];
string c, s, t;

void init(string st, int len, int nxt[][50])
{
    s = s + " ";
    memset(kmp, 0, sizeof(kmp));
    for (int i = 2; i <= len; i++)
    {
        int cur = kmp[i-1];
        while (cur != 0 && st[cur+1] != st[i])
            cur = kmp[cur];
        if (st[cur+1] == st[i])
            cur++;
        kmp[i] = cur;
    }
    for (int i = 0; i <= len; i++)
        for (int ch = 'a'; ch <= 'z'; ch++)
    {
        int cur = i;
        while (cur != 0 && st[cur+1] != ch)
            cur = kmp[cur];
        if (st[cur+1] == ch)
            cur++;
        nxt[i][ch-'a'] = cur;
    }
    return ;
}


int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> c >> s >> t;
    int lens = s.length(), lent = t.length();
    c = " " + c, s = " " + s, t = " " + t;
    init(s, lens, next_s);
    init(t, lent, next_t);
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < 60; j++)
            for (int k = 0; k < 60; k++)
                dp[i][j][k] = -maxc;
    dp[0][0][0] = 0;
    for (int i = 0; i < c.length()-1; i++)
        for (int j = 0; j <= lens; j++)
            for (int k = 0; k <= lent; k++)
                for (int ch = 'a'; ch <= 'z'; ch++)
                    if (c[i+1] == '*' || c[i+1] == ch)
        {
            if (i == 2 && j == 2 && k == 0)
            {
                i = 2;
            }
            int ls = next_s[j][ch-'a'], lt = next_t[k][ch-'a'];
            int tmp = dp[i][j][k] + (ls == lens) - (lt == lent);
            dp[i+1][ls][lt] = max(dp[i+1][ls][lt], tmp);
        }
    int ans = -maxc;
    for (int i = 0; i <= lens; i++)
        for (int j = 0; j <= lent; j++)
            ans = max(dp[c.length()-1][i][j],ans);
    cout << ans;
    return 0;
}
