#include <bits/stdc++.h>

using namespace std;

int root[10001];
int n;
int getroot(int u)
{
    if (root[u] == 0)
        return u;
    else return (root[u] = getroot(root[u]));
}
int main()
{
    memset(root, 0, sizeof(root));
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (w == 1)
        {
            int _u = getroot(u);
            int _v = getroot(v);
            if (_u != _v)
                root[_u] = _v;
        }
        if (w == 2)
        {
            int _u = getroot(u);
            int _v = getroot(v);
            if (_u != _v)
                cout << 0; else cout << 1;
            cout << endl;
        }
    }
    return 0;
}
