#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3+100, maxc = 1e9;
int n;
int s[maxn], dp[maxn][maxn], has[maxn];
vector <int> e[maxn];


void solve(int x, int p=0) {
	s[x] = (e[x].size()==1);
	for (int i: e[x])
        {
            if (i == p)
                continue;
            solve(i,x), s[x]+=s[i];
        }
	for (int i=0;i<=n;i++)
        dp[x][i] = maxc, has[i] = 0;
	dp[x][0] = 0;
	has[0] = 1;
	for (int v : e[x])
    {
        if (v == p)
            continue;
        for (int j = s[x]; j >= 0; j --)
        {
            if (!has[j])
                continue;
            for (int i = 0; i <= min(s[v], s[x]-j); i++)
            {
                dp[x][j+i] = min(dp[x][j+i], dp[v][i]+dp[x][j]);
                has[j+i] = 1;
            }
        }
    }
	for (int i=0;i<=s[x];i++)
        dp[x][s[x]-i] = min(dp[x][s[x]-i],1+dp[x][i]);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n == 2)
        return cout << 1, 0;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int root = 1;
    while (e[root].size()==1)
        root++;
    solve(root, 0);
    cout << dp[root][s[root]/2];
    return 0;
}
