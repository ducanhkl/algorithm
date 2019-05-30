/*
#include <bits/stdc++.h>
#define maxN 5005
#define sigma 26
using namespace std;
const int MOD=1000000007;
char str[maxN];
int n,i,j,act;
int sol[maxN];
int dp[maxN][sigma];
int main()
{
    freopen("inp.txt","r",stdin);
    scanf("%d\n%s",&n,str+1);
    for(i=1;i<=n;i++)
    {
        int curr=str[i]-'a';
        act=1;
        for(j=1;j<=n;j++)
        {
            sol[j]=(sol[j]-dp[j][curr]+MOD)%MOD;
            dp[j][curr]=act;
            act=(act+sol[j])%MOD;
            sol[j]=(sol[j]+dp[j][curr])%MOD;
        }
    }
    printf("%d",sol[n]);
    return 0;
}
*/

#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, m = 0;
int f[maxn], h[maxn], g[maxn];

int main()
{
    memset(h, 0, sizeof(h));
    memset(g, 0, sizeof(g));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
        if (f[i] == i)
        {
            h[++m] = i;
            g[i] = m;
        }
    }
    for (int i  = 1; i <= n; i++)
        if (f[i] != i)
    {
        if (f[f[i]] != f[i])
            return  cout << -1, 0;
        g[i] = g[f[i]];
    }
    cout << m << endl;
    for (int i = 1; i <= n; i++)
        cout << g[i] << " ";
    cout << endl;
    for (int i = 1; i <= m; i++)
        cout << h[i] << " ";
}
