#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 100003

using namespace std;

vector <int> a[maxn];
int reg[maxn], dd[maxn], k, m, n;
stack <int> s;

int check()
{
    int ans = 0, v;
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        ans ++;
        dd[u] = true;
        for (int i = 0;i<a[u].size(); i++)
            if (reg[a[u][i]] > 0)
        {
            int v = a[u][i];
            reg[v] --, reg[u] --;
            if (reg[v] < k && !dd[v])
                s.push(v);
        }
    }
    return ans;
}
int main()
{
    /freopen("inp.txt", "r", stdin);
    memset(dd, 0, sizeof(dd));
    memset(reg, 0, sizeof(reg));
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        reg[u] ++;
        reg[v] ++;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (reg[i] < k)
            s.push(i);
    cout << n-check() << endl;
    for (int i = 1; i <= n; i++)
        if (!dd[i]) cout << i << " ";
	return 0;
}
