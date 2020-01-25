#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
deque <int> q;
int sz[maxn], in[maxn], n, res[maxn], last = 1;
vector <int> e[maxn];


bool dfs(int u, int par, int dis)
{
    if (sz[dis] != -1 && sz[dis] != e[u].size())
        return false;
    sz[dis] = e[u].size();
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        if (!dfs(v, u, dis+1))
            return false;
    }
    return true;
}


void check(int u)
{
    for (int i = 0; i < maxn; i++) sz[i] = -1;
    if (!dfs(u, u, 0))
        return ;
    cout << u;
    exit(0);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        in[i] = e[i].size();
    for (int i = 1;  i<= n; i++)
        if (in[i] == 1)
            q.push_front(i);
    while(q.size())
    {
        int u = q.front();
        q.pop_front();
        last = u;
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i];
            in[v] --;
            if (in[v] == 1)
                q.push_back(v);
        }
    }
    check(last);
    for (int i = 0; i < e[last].size(); i++)
    {
        int u = e[last][i];
        int pre = last, d = 1;
        while (e[u].size() == 2)
        {
            if (e[u][0] == pre)
                pre = e[u][1];
            else
                pre = e[u][0];
            swap(pre, u);
            d++;
        }
        if (e[u].size() == 1)
            res[d] = u;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (res[i])
    {
        check(res[i]);
        cnt ++;
        if (cnt >= 3)
            break;
    }
    cout << -1;
    return 0;
}
