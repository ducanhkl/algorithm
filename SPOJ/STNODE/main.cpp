#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e4+100;

typedef vector <int> vi;

int n, m, s, t;
int num[maxn], trc[maxn];
vector <int> e[maxn];

vi getpath(int in, int out)
{
    queue <int> q;
    q.push(in);
    trc[in] = in;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : e[u])
        {
            if (trc[v])
                continue;
            trc[v] = u;
            q.push(v);
        }
    }
    vi res;
    while (out != in)
    {
        res.push_back(out);
        out = trc[out];
    }
    res.push_back(in);
    reverse(res.begin(), res.end());
    return res;
}

int bfs(int x)
{
    int res = 0;
    queue <int> q;
    q.push(x);
    trc[x] = x;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : e[u])
        {
            if (trc[v] == 0 && num[v] == 0)
            {
                trc[v] = u;
                q.push(v);
            } else
            {
                res = max(res, num[v]);
            }
        }
    }
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    vi path = getpath(s, t);
    for (int i = 0; i < path.size(); i++)
        num[path[i]] = i+1;
    memset(trc, 0, sizeof(trc));
    int now = 0, ans = 0;
    for (int i = 0; i < path.size(); i++)
    {
        if (i+1 >= now && path[i] != s && path[i] != t)
            ans ++;
        now = max(now, bfs(path[i]));
    }
    cout << ans;
    return 0;
}
