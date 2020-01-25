#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5+100;
int n, m;
set <int> e[maxn];
set <int> ve;
int dd[maxn];
int cnt = 0;

void dfs(int u)
{
//    dd[u] = 1;
//    ve.erase(u);
//    vector <int> ds;
//    for (int v : ve)
//        {
//            if (e[u].count(v))
//                continue;
//            ds.push_back(v);
//        }
//    for (int v : ds)
//    {
//        ve.erase(v);
//        dd[v] = 1;
//        dfs(v);
//    }
    dd[u]=1;
    ve.erase(u);
    vector<int> ret;
    for(auto i : ve)
    {
        if(!e[u].count(i))
        {
            ret.push_back(i);
        }
    }
    for(int i : ret)
    {
        ve.erase(i);
    }
    for(auto i:ret)
    {
        dd[i]=1;
        dfs(i);
    }
    return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        ve.insert(i);
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].insert(v);
        e[v].insert(u);
    }
    for  (int i = 1; i <= n; i ++)
    {
if (dd[i] == 1)
    continue;
        cnt++;
        dfs(i);
    }
    cout << cnt-1;
    return 0;
}
