#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;
int n;
int root[maxn][3], cnt[maxn][3];
long long ans = 0;

int getroot(int u, int w)
{
    if (root[u][w] == 0)
        return u;
    else
        return
            root[u][w] = getroot(root[u][w], w);
}


void add(int u, int v, int w)
{
    int rootu = getroot(u, w);
    int rootv = getroot(v, w);
    if (rootu == rootv)
        return ;
    root[rootu][w] = rootv;
    cnt[rootv][w] += cnt[rootu][w];
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    memset(root, 0 , sizeof(root));
    for (int i = 1; i <= n; i++)
        cnt[i][1] = cnt[i][0] = 1;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u , v , w);
    }
    for (int i  = 1; i <= n; i++)
    {
        int r1 = getroot(i, 0);
        int r2 = getroot(i, 1);
        ans += 1LL*cnt[r1][0]*cnt[r2][1]-1;
    }
    cout << ans;
    return 0;
}
