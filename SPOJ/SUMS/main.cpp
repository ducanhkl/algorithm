#include <bits/stdc++.h>
#define maxm 50010
#define maxn 5010

using namespace std;

int n, m;
int f[maxm], a[maxn];

bool check(int &x, int y)
{
    if (x > y)
    {
        x = y;
        return true;
    }
    return false;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < maxm; i++)
        f[i] = INT_MAX;
    f[0] = 0;
    queue <int> q;
    q.push(0);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= n; i++)
        {
            int v = (u+a[i])%a[1];
            if (check(f[v], f[u] + a[i]))
                q.push(v);
        }
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        if (x >= f[x%a[1]])
            cout << "TAK";
        else cout << "NIE";
        cout << endl;
    }
    return 0;
}
