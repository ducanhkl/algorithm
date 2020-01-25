/*#include <bits/stdc++.h>
#define maxn 300006

using namespace std;

int m, n, s;
vector <pair <int, int> > e[maxn];
vector <int> tt[maxn];
const long long maxc = 1e14+1;
long long d[maxn];
int use[maxn], res = 0;
int ans[maxn];

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
        tt[u].push_back(i);
        tt[v].push_back(i);
    }
    cin >> s;
    priority_queue <pair<long long, int> > q;
    q.push({0, s});
    for (int i = 0; i < maxn; i++)
        d[i] = maxc;
    d[s] = 1;
    while(q.size())
    {
        int u = q.top().second;
        int l = -q.top().first;
        q.pop();
        if (l > d[u])
            continue;
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i].first;
            long long w = e[u][i].second;
            if (d[u] + w == d[v] && w > use[v])
                continue;
            if (d[u] + w <= d[v])
            {
                d[v] = d[u]+w;
                ans[v] = tt[u][i];
                use[v] = w;
                q.push({-d[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (i != s)
            res += use[i];
    cout << res << endl;
    for (int i = 1; i <= n; i++)
        if (i != s)
            cout << ans[i] << " ";
    return 0;
}
*/
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class xau
{
private:
    char a[100];
    int n;
    xau()
    {
        memset(a, 0, sizeof(a));
    }
    xau(char x[100])
    {
        for (int i = 1; i <= n; i++)
            a[i] = x[i];
    }
    void xem()
    {
        for (int i = 0; i < 100; i++)
        {
            if (a[i] == 0)
                break;
            cout <<a[i];
        }
        cout << endl;
    }
    void doichuhoa()
    {
        for (int i = 0; i < 100; i++)
            if (a[i] >= 'a' && a[i] <= 'z')
                a[i] -= 32;
    }
    char* trichphai(int n)
    {
        char s[100];
        int l = 0, sz = 1;
        while (sz < 100 && a[sz-1] != 0)
            sz ++;
        for (int i = sz; i >= n-sz+1; i--)
            s[l++] = a[i];
        return s;
    }
    char* trichtrai(int n)
    {
        char s[100];
        int l = 0, sz = 1;
        while (sz < 100 && a[sz-1] != 0)
            sz ++;
        for (int i = 0; i < sz; i--)
            s[l++] = a[i];
        return s;
    }
    void timkiem(char s[])
    {
        int sz = 0;
        while (sz < 100 && s[sz-1] != 0)
            sz ++;
        for (int i = 0; i < 100; i++)
        {
            int ck = 1;
            for (int j = 0; j < sz; j++)
                if (a[i+j] != s[j])
            {
                ck = false;
                break;
            }
            if (ck)
            {
                cout << "Co" << endl;
                return;
            }
        }
    }
    friend xau operator+ (xau &a, xau b);
};

xau operator+ (xau &a, xau b)
{

    int sz1 = 0, sz2 = 0;
    while (sz1 < 100 && a.a[sz1-1] != 0)
        sz1 ++;
    while (sz2 < 100 && b.a[sz2-1] != 0)
        sz2 ++;
    for (int i = 0; i < sz2; i++)
        a.a[sz1+1] = b.a[i];
}
int main()
{

    return 0;
}
