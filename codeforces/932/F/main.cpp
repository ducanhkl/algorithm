#include<bits/stdc++.h>
using namespace std;



int n,a[110000],b[110000],ch[110000],que[110000],temp1,temp2,temp,vis[110000],times;
long long dp[110000],inf=1e18;
vector<int>adj[110000];
void bfs(int id,int ie)
{
	int deep=0,i,j;
	que[0]=ie;
	temp1=temp2=0;
	temp=1;
	vis[ie]=times;
	while(temp1<=temp2&&deep++<20)
	{
        for(i=temp1;i<=temp2;i++)
        {
        	ie=que[i];
        	if(dp[id]>dp[ie]+1LL*a[id]*b[ie])
        	{
	        	dp[id]=dp[ie]+1LL*a[id]*b[ie];
	        	ch[id]=ie;
	        }
	        for(j=0;j<adj[ie].size();j++)
     		    if(vis[adj[ie][j]]!=times)
     		    {
	               vis[adj[ie][j]]=times;
   		           que[temp++]=adj[ie][j];
     		    }
        }
        temp1=temp2+1;
        temp2=temp-1;
	}
}
void dfs(int id,int pr)
{
	int i,j,s,p,q,ip;
	dp[id]=inf;
	for(i=0;i<adj[id].size();i++)
	{
		ip=adj[id][i];
		if(ip!=pr)
		{
            dfs(ip,id);
            times++;
            vis[id]=times;
	    	bfs(id,ch[ip]);
		}
	}
	if(dp[id]==inf)
	{
		dp[id]=0;
		ch[id]=id;
	}
}
int main()
{
    freopen("inp.txt", "r", stdin);
	scanf("%d",&n);
	int i,j,s,p,q;
	for(i=0;i<n;i++)
	   scanf("%d",&a[i]);
    for(i=0;i<n;i++)
       scanf("%d",&b[i]);
    int u,v;
    for(i=0;i<n;i++)
       adj[i].clear();
    for(i=0;i<n-1;i++)
    {
    	scanf("%d%d",&u,&v);
    	u--;
    	v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    dfs(0,-1);
    for(i=0;i<n;i++)
    {
    	if(i)
    	   putchar(' ');
 	    printf("%lld",dp[i]);
    }
    printf("\n");
}
