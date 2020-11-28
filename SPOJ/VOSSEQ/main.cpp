#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e6+100;


vector <int> ans;
map<int, int> cnt;
int m, n;
int a[maxn];
vector <int> e[maxn];

void solve()
{
    priority_queue <int> q;
    for (int i = 1;i <= n; i++)
    {
        if (cnt[i] == 0)
        {
            q.push(-i);
        }
    }
    while(q.size())
    {
        int u = -q.top();
        q.pop();
        ans.push_back(u);
        for (auto v: e[u])
        {
            cnt[v] --;
            if (cnt[v] == 0)
            {
                q.push(-v);
            }
        }
    }
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++)
        {
            cin >> a[i];
            n = max(n, a[i]);
        }
        for (int i = 1; i < k; i++)
        {
            e[a[i]].push_back(a[i+1]);
            cnt[a[i+1]] ++;
        }
    }
    solve();
    for (auto v : ans)
    {
        cout << v << " ";
    }
    return 0;
}
