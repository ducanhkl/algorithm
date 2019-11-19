#include <cstdio>
#include <cstring>
#include <bits/stdc++.h>

using namespace std;
int n;
int v[1500];
int p[10][1500];
int cnt[10];
int id[1500];
int l,r,mid,ans=-1;
int f[1500][256];
bool check(int u)
{
	int ret=0;
	memset(f,0,sizeof(f));
	for (int i = 0; i <= n; i++)
        for (int j = 0; j < 256; j++)
            f[i][j] = -12346;
	f[0][0]=0;
	for (int i=1;i<=n;i++)
		for (int j=0;j<256;j++)
		{
			if (j&(1<<(v[i]-1)))
			{
				if (id[i]-u+1 > 0 && p[v[i]][id[i]-u+1]>0)
					if (f[p[v[i]][max(0, id[i]-u+1-1)]][j^(1<<v[i]-1)]+u>f[i][j])
						f[i][j]=f[p[v[i]][id[i]-u+1]-1][j^(1<<v[i]-1)]+u;
				if (id[i]-u+1 >= 0 && p[v[i]][id[i]-u]>0)
					if (f[p[v[i]][id[i]-u]-1][j^(1<<v[i]-1)]+u+1>f[i][j])
						f[i][j]=f[max(p[v[i]][id[i]-u]-1, 0)][j^(1<<v[i]-1)]+u+1;
				if (u!=0)
					if (j==255&&f[i][j]>ret)
						ret=f[i][j];
				if (u==0)
					if (f[i][j]>ret)
						ret=f[i][j];
			}
			if (f[i-1][j]>f[i][j])
				f[i][j]=f[i-1][j];
		}
	if (ret>ans)
		ans=ret;
	return ret;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&v[i]);
		cnt[v[i]]++;
		id[i]=cnt[v[i]];
		p[v[i]][id[i]]=i;
	}
	ans = -1;
	l=0;
	r=3;
	while (l<=r)
	{
		mid=(l+r)>>1;
		if (check(mid)>0)
			l=mid+1;
		else
			r=mid-1;
	}
	printf("%d\n",ans);
	return 0;
}
