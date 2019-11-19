#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;
int n, m;
int r[maxn], root[maxn], g[maxn][2];

int getroot(int u)
{
    return u == root[u]?u:root[u] = getroot(u);
}

void mg(int u, int v)
{
    u = getroot(u);
    v = getroot(    v);
    if (u != v)
        root[u] = v;
    return ;
}

int main()
{
    memset(root, 0, sizeof(root));
    memset(g, 0, sizeof(g));
    //ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        scanf("%d", r+i);
    for (int i = 1; i <= m; i++)
    {
        root[i] = i;
        root[i+m] = i+m;
        int c;
        scanf("%d", &c);
        for (int j = 1; j <= c; j++)
        {
            int x;
            scanf("%d", &x);
            if (g[x][0])
                g[x][1] = i;
            else
                g[x][0] = i;
        }
    }
	for(int i=1;i<=n;i++){
		if(r[i]==0)
			mg(g[i][0],g[i][1]+m),
			mg(g[i][0]+m,g[i][1]);
		else
			mg(g[i][0],g[i][1]),
			mg(g[i][0]+m,g[i][1]+m);
	}
    for (int i = 1; i <= m; i++)
        if (getroot(i) == getroot(i+m))
            return printf("NO"), 0;
    printf("YES");
    return 0;
}
