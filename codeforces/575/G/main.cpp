#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
typedef pair <int, int> pii;
int n, m;
vector <pii> e[maxn];
vector <int> zr;
queue <vector<int> > q;
int ufr[maxn], par[maxn];
char ch[maxn];

void init()
{
    queue <int> qq;
    qq.push(n-1);
    while (qq.size() )
    {
        int u = qq.front();
        qq.pop();
        zr.push_back(u);
        for (auto [v, w] : e[u])
        {
            if (!w && !ufr[v])
            {
                qq.push(v);
                ufr[v] = 1;
                par[v] = u;
                ch[v] = '0';
            }
        }
    }
}

void solve()
{
    q.push(zr);
    while (q.size())
    {
        vector <int> now = q.front();
        q.pop();
        vector <pii> w[10];
        for (int i = 0; i < now.size(); i++)
        {
            int u = now[i];
            for (int j = 0; j < e[u].size(); j++)
            {
                int to = e[u][j].first;
                int co = e[u][j].second;
                if (!ufr[to])
                    w[co].push_back({to, u});
            }
        }
        vector <int> t ;
        for (int i = 0; i < 10; i++)
        {
            t.resize(0);
            for (int j = 0; j < w[i].size(); j++)
            {
                int to = w[i][j].first;
                int u = w[i][j].second;
                if (!ufr[to])
                {
                    t.push_back(to);
                    ufr[to] = 1;
                    par[to] = u;
                    ch[to] = '0'+i;
                }
            }
            if (t.size())
            {
                q.push(t);
            }
        }
    }
    return ;
}


void check(string str)
{
    if (n == -1 && m == 1000)
        cout << str << endl;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    check("debug");
    init();
    check("debug1");
    solve();
    for (int i = 0; i < e[22].size(); i++)
    {
        check(to_string(e[22][i].first));
        check(to_string(e[22][i].second));
    }
    int g=0,z=1;
    vector <int> ans = {0};
    check(to_string(par[22]));
    while (g!=n-1)
    {
        g = par[g];
        ans.push_back(g);
    }
    check("debug3");
    for (int i = ans.size()-2; i>=0; i--)
    {
        if (ch[ans[i]]!='0')
            cout<<ch[ans[i]],z=0;
        else
            if (!z)
                cout<<'0';
    }
    if (z)
        cout<<0;
    cout << endl;
    cout << ans.size()<< endl;
    for (auto i:ans)
        cout << i << " ";
    return 0;
}
