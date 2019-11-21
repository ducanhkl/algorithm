#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

long long  n,x,y,z,vt,cnt;
set<int> pos[maxn];
long long dis[maxn];
int check[maxn];
long long ans[maxn];

void dfs(int vt)
{
    for(auto i: pos[ans[vt]])
        if (check[i]==0)
        {
            ans[cnt++]=i;
            check[i]=1;
        }
    if (vt<n-2)
        dfs(vt+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<n-2; i++)
    {
        cin >> x >> y >> z;
        pos[x].insert(y);
        pos[x].insert(z);
        pos[y].insert(x);
        pos[y].insert(z);
        pos[z].insert(x);
        pos[z].insert(y);
        dis[x]++,dis[y]++,dis[z]++;
    }
    for(int i=1; i<=n; i++)
        if (dis[i]==1)
        {
            vt = i;
            break;
        }
    ans[1]=vt;
    check[vt]=1;
    for(auto i: pos[vt])
        if (dis[i]==2 && check[i]==0)
        {
            ans[2]=i;
            check[i]=1;
            break;
        }
    cnt=3;
    dfs(1);
    for(int i=1; i<=n; i++)
        cout << ans[i]<<' ';
    return 0;
}
