#include <bits/stdc++.h>

using namespace std;

const int maxn = 400;

int n, cnt = 0;
int ufr[maxn], num[maxn], dd[maxn];
vector <int> e[2*maxn], ve[maxn];

void dfs(int u)
{
    ufr[u] = cnt;
    ve[cnt].push_back(u);
    for (auto v : e[u])
    {
        if (ufr[v] == 0)
            dfs(v);
    }
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    int u, v;
    while (cin >> u >> v)
    {
        e[u].push_back(n+v);
        e[n+v].push_back(u);
        e[v].push_back(n+u);
        e[n+u].push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (ufr[i] == 0)
        {
            cnt ++;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (ufr[i] == ufr[j] && ufr[i] == ufr[n+j])
            {
                cout << "YES";
                return 0;
            }
        }
    }
    vector <int> res;
    for (int i = 1; i <= cnt; i++)
    {
        vector <int> v1, v2;
        for (auto u : ve[i])
        {
            if (u > n)
                v2.push_back(u-n);
            if (dd[u])
            {
                v1.resize(0);
                v2.resize(0);
                continue;
            }
            if (u >= n && dd[u-n])
            {
                v1.resize(0);
                v2.resize(0);
                continue;
            }
            if (u <= n)
            {
                v1.push_back(u);
            }
        }
        if (v1.size() >= ve[i].size() - v1.size())
        {
            for (auto v : v1)
            {
                dd[v] = 1;
                res.push_back(v);
            }
            for (auto v : v2)
            {
                dd[v] = 1;
            }
        }

    }
    cout << "No" << endl;
    cout << res.size() << endl;
    sort(res.begin(), res.end());
    for (auto u : res)
        cout <<u  << " ";
    return 0;
}
