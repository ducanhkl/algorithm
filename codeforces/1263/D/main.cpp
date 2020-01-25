#include <bits/stdc++.h>

using namespace std;


const int maxn = 3e5+100;


vector <int> e[maxn];
int ufr[maxn];
long long a[maxn];
int cnt = 0, n;

void dfs(int u)
{
    ufr[u] = 1;
    for (auto v : e[u])
    {
        if (ufr[v])
            continue;
        dfs(v);
    }
    return ;
}

void init()
{
    for (int i = 0; i <= 30; i++)
    {
        int u = n+i+1;
        long long val = (1LL<<i);
        for (int j = 1; j <= n; j++)
        {
            if (val&a[j])
            {
                e[u].push_back(j);
                e[j].push_back(u);
            }
        }
    }
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (ufr[i] == 0)
        {
            cnt ++;
            dfs(i);
        }
    }
    cout << cnt;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        long long val  = 0;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
            val |= (1 << (s[i] - 'a'));
        a[i] = val;
    }
    init();
    solve();
    return 0;
}
