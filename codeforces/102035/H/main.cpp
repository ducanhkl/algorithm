#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, m;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u < v)
            cout << 0;
        else
            cout << 1;
    }
    return 0;
}
