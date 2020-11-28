#include <bits/stdc++.h>

using namespace std;


#define SetLength2(a, n, t) a = ((t *)calloc(n, sizeof(t))) + (n) / 2

int *num, *low, *dd, *color;
int n,  m;
vector <int> *e;
int result= true;
int counter = 0;
stack <int> s;

void set_color(int u, int c)
{
    if (color[u] == (3^c))
        result = false;
    else
        color[u] = c;
    if (color[-u] == c)
        result = false;
    else
        color[-u] = 3^c;
}

void dfs(int u)
{
    counter ++;
    num[u] = low[u] = counter;
    s.push(u);
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (dd[v])
            continue;
        if (num[v] != 0)
            low[u] = min(low[u], num[v]);
        else
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (num[u] == low[u])
    {
        int v;
        if (color[u] == 0)
        {
            set_color(u, 2);
        }
        do
        {
            v = s.top();
            set_color(v, color[u]);
            s.pop();
            dd[v] = 1;
        }
        while (v!=u && !s.empty());
    }
}


void init()
{
    SetLength2(e, 2*n+5, vector<int>);
    SetLength2(color, 2*n+5, int);
    SetLength2(num, 2*n+5, int);
    SetLength2(low, 2*n+5, int);
    SetLength2(dd, 2*n+5, int);
}
void input()
{
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[-u].push_back(v);
        e[-v].push_back(u);
    }
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (dd[i] == 0)
        {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if(dd[-i] == 0)
        {
            dfs(-i);
        }
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    init();
    input();
    solve();
    if (result)
    {
        cout << "YES" << endl;
        vector <int> ans;
        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 2)
            {
                ans.push_back(i);
            }
        }
        cout << ans.size() << endl;
        for (auto v: ans)
            cout << v << " ";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
