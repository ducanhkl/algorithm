/*#include <bits/stdc++.h>

using namespace std;

void visit(int u)
{
    num[u] = low[u] = cnt++;
    s.push_back(u);
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i].first;

    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    visit(1);
    for (int u = 1; u <= n; u++)
        for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i].first;
        int w = e[u][i].second;
        if (tplm[v] == tplm[u])
            b[tplm[v]] += calc(w);
        else
            g[tplm[u]].push_back(tplm[v]);
    }
    cin >> p;
    cout << dfs(tplm[p]);
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll d[23333],mx=20000;
ll cal(int x){
	int l=0,r=mx,mid;
	for (;l+3<r;x>=mid*(mid+1)/2? l=mid: r=mid) mid=l+r>>1;
	for (;;++l) if (l*(l+1)/2<=x&&x<(l+1)*(l+2)/2) return x*(l+1ll)-d[l];
}

int n,m,p,x,y,z;
struct R{
	int to; ll val;
};
#define N 1001000
vector<R>G[N],dag[N];
int bel[N],tot,dfn[N],dft,low[N],st[N],tp;
ll v[N],f[N];

void dfs(int x){
	dfn[x]=low[x]=++dft;
	st[++tp]=x;
	for (auto y:G[x]){
		if (!dfn[y.to]){
			dfs(y.to);
			low[x]=min(low[x],low[y.to]);
		}else if (!bel[y.to]){
			low[x]=min(low[x],dfn[y.to]);
		}
	}
	if (dfn[x]==low[x]){
		bel[x]=++tot;
		for (;st[tp]!=x;) bel[st[tp--]]=tot;
		--tp;
	}
}

ll que(int x){
	if (~f[x]) return f[x]; ll res=0;
	for (auto y:dag[x]) res=max(res,y.val+que(y.to));
	return f[x]=res+v[x];
}

int main()
{
    freopen("inp.txt", "r", stdin);
	for (int i=1;i<=mx;i++) d[i]=d[i-1]+i*(i+1)/2;
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		G[x].push_back((R){y,z});
	}
	cin>>p; dfs(p);
	for (int i=1;i<=n;i++){
		for (auto o:G[i]){
			x=bel[i], y=bel[o.to];
			if (x==y) v[x]+=cal(o.val);
			else dag[x].push_back((R){y,o.val});
		}
	}
	memset(f,-1,sizeof f);
	cout<<que(bel[p]);
}
*/

#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 1e6+100;

int n, m, t;
int num[maxn], low[maxn], cnt[maxn], ufr[maxn];
long long hei[maxn], ans = 0, dp[maxn], ss[maxn], st[maxn];
int comcounter = 0, counter = 0;
vector <pair<int, long long> > e[maxn], e1[maxn];
stack <int> s;

void reset()
{
    for (int i = 0; i < maxn; i++)
        dp[i] = -1;
    memset(num, 0, sizeof(num));
    memset(low, 0, sizeof(low));
    memset(cnt, 0, sizeof(cnt));
    memset(hei, 0, sizeof(hei));
    memset(ufr, 0, sizeof(ufr));
}
long long calc(long long x)
{
    long long pos1 = upper_bound(ss, ss+maxn, x) - ss;
    return pos1*x - st[pos1-1];
}

void visit(int u)
{
    num[u] = low[u] = ++counter;
    s.push(u);
    for (int i = 0; i < (int)e[u].size(); i++)
    {
        int v = e[u][i].first;
        if (ufr[v])
            continue;
        if (num[v] != 0)
            low[u] = min(low[u], num[v]);
        else
        {
            visit(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (num[u] == low[u])
    {
        comcounter ++;
        int v;
        do
        {
            v = s.top();
            ufr[v] = 1;
            s.pop();
            cnt[v] = comcounter;
        } while  (v != u);
    }
}

long long dfs(int u)
{
    if (dp[u] != -1)
        return dp[u];
    dp[u] = hei[u];
    long long res = 0;
    for (int i = 0; i < e1[u].size(); i++)
    {
        int v = e1[u][i].first;
        long long w  = e1[u][i].second;
        res = max(res, w+dfs(v));
    }
    dp[u] += res;
    return dp[u];
}

int32_t main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    reset();
    for (int i = 1; i < maxn; i++)
    {
        ss[i] = ss[i-1]+i;
        st[i] = st[i-1] + ss[i];
    }
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++)
        if (!ufr[i])
            visit(i);
    cin >> t;
    for (int u = 1;  u <= n; u++)
        for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i].first;
        long long w = e[u][i].second;
        if (cnt[u] == cnt[v])
            hei[cnt[u]] += calc(w);
        if (cnt[u] != cnt[v])
            e1[cnt[u]].push_back({cnt[v], w});
    }
    cout << dfs(cnt[t]);
    return 0;
}
