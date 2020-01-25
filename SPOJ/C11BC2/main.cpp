#include <bits/stdc++.h>
#define maxn 10001

using namespace std;

int n, m;
int root[maxn];

int getroot(int u)
{
    if (root[u] == 0)
        return u;
    else return (root[u] = getroot(root[u]));
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(root, 0, sizeof(root));
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
    {
        int x, k;
        cin >> x >> k;
        if (k == 1)
        {
            int _u = getroot(i);
            int _v = getroot(x);
            if (_u != _v)
                root[_u] = _v;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        int _u = getroot(u);
        int _v = getroot(v);
        if (_u != _v)
            cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}
