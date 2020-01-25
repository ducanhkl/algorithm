#include <bits/stdc++.h>
#define maxn 10005

using namespace std;

long long mx[maxn][200], mn[maxn][200], trace[maxn];
string s;
int p, m, n, node = 0, pm, dd;
stack <int> q;

int dfs(int l, int r)
{
    int dd = (int)(p < m);
    node ++;
    int x = node;
    if (l == r)
    {
        mx[node][0] = mn[node][0] = s[l] - '0';
        return x;
    }
    int pos;
    if (s[l+1] == '(')
        pos = trace[l+1]+1;
    else pos = l+2;
    int l2 = dfs(l+1, pos-1), r2 = dfs(pos+1, r-1);
    for (int j = dd; j <= pm; j++)
        for (int k = 0; k <= j-dd; k ++)
    {
        mx[x][j] = max(mx[x][j], mx[l2][k] + mx[r2][j-dd-k]);
        mn[x][j] = min(mn[x][j], mn[l2][k] + mn[r2][j-dd-k]);
    }
    for (int j = !dd; j <= pm; j++)
        for (int k = 0; k <= j-!dd; k++)
    {
        mx[x][j] = max(mx[x][j], mx[l2][k] - mn[r2][j-!dd-k]);
        mn[x][j] = min(mn[x][j], mn[l2][k] - mx[r2][j-!dd-k]);
    }
    return x;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < 200; j++)
    {
        mx[i][j] = INT_MIN;
        mn[i][j] = INT_MAX;
    }
    ios_base::sync_with_stdio(false);
    cin >> s >> p >> m;
    pm = min(p, m);
    int n = s.length();
    s = " " + s;
    for (int i = n; i >= 1; i--)
        {
            if (s[i] == ')')
            {
                q.push(i);
            }
            if (s[i] == '(')
            {
                trace[i] = q.top();
                q.pop();
            }
        }
    int pos = dfs(1, n);
    cout << mx[pos][pm];
}
