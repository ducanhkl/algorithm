/*#include <bits/stdc++.h>
#define maxn 6000
#define ll long long

using namespace std;

int n;
long long a[maxn], b[maxn], ans[maxn], dd[maxn];
map <ll, int> m;

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void init()
{
    int cnt = 0;
    memset(ans, 0, sizeof(ans));
    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= 10000; j++)
            while (a[i] != 0 && a[i]%(j*j) == 0)
                a[i] /= (j*j);
    for (int i = 1; i <= n; i++)
        {
            if (m[a[i]] == 0)
                m[a[i]] = ++cnt;
            a[i] = m[a[i]];
        }
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        memset(dd, 0, sizeof(dd));
        int sl = 0;
        for (int j = i; j <= n; j++)
            {
                if (!dd[a[j]] && a[j] != 0)
                    sl++;
                dd[a[j]] = 1;
                ans[max(sl, 1)]++;
            }
    }
}

void output()
{
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    input();
    init();
    solve();
    output();
    return 0;
}
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=5005;

ll a[maxn],p[maxn];
ll cnt1=0,n;
ll ans[maxn];

map<ll,ll> Map;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=0)
        {
            for(ll j=2;j<=10000;j++)
            {
                while(a[i]%(j*j)==0) a[i]/=j*j;
            }
            if(Map[a[i]]==0) Map[a[i]]=++cnt1;
            a[i]=Map[a[i]];
        }
    }

    for(int i=1;i<=n;i++)
    {
        ll now=0;
        memset(p, 0, sizeof(p));
        for(int j=i;j<=n;j++)
        {
            if(a[j]!=0 && p[a[j]]==0) now++;
            p[a[j]]=1;
            ans[max(now,1LL)]++;
        }

    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
