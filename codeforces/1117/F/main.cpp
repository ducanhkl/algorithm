#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100, maxp = 20;
int n, a[maxp][maxp], ma[(1<<maxp)], cur[1<<maxp], dp[1<<maxp], cnt[maxn], f[maxp][maxn];
int ans, mp, p;
char s[maxn];
vector <int> pos[20];

void solve()
{
    dp[mp] = 1;
    for (int i = mp; i >= 0; i--)
    {
        if (!dp[i])
            continue;
        for (int j = 0; j < p; j++)
            if ((i>>j)&1)
                dp[(i^(1<<j))] = ma[(i^(1<<j))];
    }
    return ;
}

void init()
{
    for (int i = 1; i <= n; i++)
    {
        cnt[s[i]-'a'] ++;
        pos[s[i]-'a'].push_back(i);
        for (int c = 0; c < p; c++)
            f[c][i+1] = f[c][i] + (s[i] == ('a'+c));
    }
    for (int i = 0; i <= mp; i ++)
        ma[i] = 1;
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            memset(cur, 0, sizeof(cur));
            if (a[i][j])
                continue;
            int pos1 = 0, pos2 = 0;

            while (pos1 < pos[i].size() && pos2 < pos[j].size())
            {
                if (i == j && pos[i][pos1] == pos[j][pos2])
                {
                    pos2++;
                    continue;
                }
                int m = 0;
                if (pos[i][pos1] < pos[j][pos2])
                {
                    for (int c = 0; c < p; c++)
                    {
                        if (f[c][pos[j][pos2]] - f[c][pos[i][pos1]+1] != 0)
                        {
                            m |= (1<<c);
                        }
                    }
                    pos1++;
                }
                else
                {

                    for (int c = 0; c < p; c++)
                    {
                        int pp1 = f[c][pos[j][pos2]+1];
                        int pp2 = f[c][pos[i][pos1]];
                        if (f[c][pos[i][pos1]] - f[c][pos[j][pos2]+1] != 0)
                        {
                            m = m^(1<<c);
                        }
                    }
                    pos2++;
                }
                if ((m>>i)&1)
                    continue;
                if ((m>>j)&1)
                    continue;
                m = m^(mp);
                cur[m] = 1;
            }
            for (int i = 0; i <= mp; i++)
                cur[i] = !cur[i];
            for (int ii = mp; ii > 0; ii--)
            {
                if (cur[ii])
                    continue;
                for (int jj = 0; jj < p; jj++)
                {
                    if (jj != i && jj != j && (ii>>jj)&1)
                    {
                        cur[(ii^(1<<jj))] = 0;
                    }
                }
                ma[ii] &= cur[ii];

            }
        }
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> p;
    ans = n;
    mp = (1<<p)-1;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 0; i < p; i++)
        for (int j = 0;  j < p; j++)
            cin >> a[i][j];
    init();
    solve();
    for (int i = 0; i <= mp; i++)
    {
        int res = 0;
        if (!dp[i])
            continue;
        for (int j = 0; j < p; j++)
            if ((i >> j)&1)
            {
                res += cnt[j];
            }
        ans = min(ans, res);
    }
    cout << ans;
}


