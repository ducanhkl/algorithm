#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5, maxc = 1e7;
int n, k;
int q[maxn], d[maxn], de[maxn], p[maxn];
vector <int> e[maxn];
int top = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >>u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 0; i < maxn; i++)
    {
        d[i] = maxc;
       // de[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (e[i].size () == 1)
        {
            q[++top] = i;
            d[i] = 0;
        }
    }
    for (int i = 1; i <= top; i++)
    {
        int u = q[i];
        if (de[u] < 3 && d[u])
        {
            cout << "No";
            return 0;
        }
        for (auto v : e[u])
        {
            if (p[v] == u)
                continue;
            if (d[v] != maxc && d[v] != d[u]+1)
            {
                cout << "No";
                return 0;
            }
            if (d[v] == maxc)
                q[++top] = v;
            d[v] = d[u] + 1;
            p[u] = v;
            ++de[v];
        }
    }
    if (d[q[top]] != k)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}
