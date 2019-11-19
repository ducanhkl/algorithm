/*#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n, q;
int par[maxn][30], h[maxn];
vector <int> e[maxn];

void dfs(int u, int p)
{
    par[u][0] = p;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == p)
            continue;
        h[v] = h[u] + 1;
        dfs(v, u);
    }
    return ;
}

void rmq()
{
    for (int i = 1; i <= 20; i++)
        for (int u = 1; u <= n; u++)
            par[u][i] = par[par[u][i-1]][i-1];
    return ;
}

int get(int u, int len)
{
    for (int i = 20; i >= 0; i--)
        if ((len>>i)&1)
            u = par[u][i];
    return u;
}

int lca(int u, int v)
{
    if (h[u] < h[v])
        swap(u, v);
    int len = h[u] - h[v];
    u = get(u, len);
    if (u == v)
        return v;
    for (int i = 20; i >= 0; i--)
        if (par[u][i] != par[v][i])
            u = par[u][i], v = par[v][i];
    return par[u][0];
}

int dis(int u, int v)
{
    return h[u]+h[v] - 2*h[lca(u, v)]+1;
}

int calc(int s, int f, int t)
{
    return (dis(s, t) + dis(f, t) - dis(s, f)+1)/2;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        e[i].push_back(x);
        e[x].push_back(i);
    }
    memset(h, 0, sizeof(h));
    h[1] = 1;
    dfs(1, 1);
    rmq();
    for (int i = 1; i <= q; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        calc(3, 3, 2);
        ans = max(calc(a, b, c), max(calc(a, c, b), calc(c, b, a)));
        cout << ans << endl;
    }
    return 0;
}
*/

/**
 Tran Thi Thuong
 Ma SV: B18DCCN657
 Ma nhom: 16
 STT:57
 Ma lop quan ly: D18-275
 */
 #include<stdio.h>
 float mu(int x, int n)
 {
 	if (n==1)
		return x;
 	else
 	return mu(x,n-1)*x;
 }
 float gthua(int n)
 {
 	if(n==1)
		return 1;
 	else
		return n*gthua(n-1);
 }
int main ()
{
	int x, n;
	printf("nhap x,n:");
	scanf("%d%d",&x,&n);
	float B = 1;
	for (int i=1;i<=n;i++)
	{
		B=B+mu(x,i)*1.0/gthua(i);
	}
	printf("B=%3f",B);
	return 0;
}
