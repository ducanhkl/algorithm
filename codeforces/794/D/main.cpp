#include <bits/stdc++.h>

#define reset(a) memset((a), 0, sizeof(a))

using namespace std;

const long long maxn = 3e5+100, mod = 1e9+7;
vector <int> e[maxn];
long long iha[maxn], ha[maxn];
int ufr[maxn], use[maxn*10], ans[maxn];
int n, m;

void dfs(int u)
{
    ufr[u] = 1;
    for (auto v: e[u])
    {
        if (ha[u] == ha[v])
        {
            ans[v] = ans[u];
        }
    }
    for (auto v: e[u])
    {
        if (ufr[v] != 0)
        {
            if (abs(ans[u]-ans[v])>1)
            {
                cout << "NO";
                exit(0);
            }
        }
        else
        {
            if (ans[v] == 0)
                for (int i = ans[u]-1; i <= ans[u]+1; i++)
                    if (use[i] == 0)
                    {
                        use[i] = 1;
                        ans[v] = i;
                        break;
                    }
            dfs(v);
        }
    }
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    reset(iha), reset(use), reset(ufr), reset(ans);
    cin >> n >> m;
    iha[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        iha[i] = (iha[i-1]*47+i)%mod;
        ha[i] = iha[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ha[u] += iha[v];
        ha[v] += iha[u];
        ha[u] %= mod;
        ha[v] %= mod;
    }
    ans[1] = 1e6;
    use[ans[1]] = 1;
    dfs(1);
    for (int i = 1; i <= n; i++)
        if (ans[i] == 0)
            return cout << "NO", 0;
    cout << "YES \n";
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}
