#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
using namespace std;
#define N 45
int n,m,c[N][2],nxt[N];char s[N];ll ans,f[N][N][N];
int main()
{
    freopen("inp.txt", "r", stdin);
	scanf("%d%s",&n,s+1);m=strlen(s+1);
	rep (i,1,m) c[i-1][s[i]-'0']=i;
	rep (i,1,m)
        rep (j,0,1)
            if (c[i][j]) nxt[c[i][j]]=c[nxt[i]][j];
                else c[i][j]=c[nxt[i]][j];
	ans=1ll<<n;
	rep (i,0,m-1){
		memset(f,0,sizeof(f));
		f[0][0][i]=1;
		rep (j,0,n-1) rep (k,0,m-1) rep (l,0,m-1)
			if (f[j][k][l])
				rep (t,0,1) f[j+1][c[k][t]][c[l][t]]+=f[j][k][l];
		rep (j,0,m-1) ans-=f[n][i][j];
	}
	cout<<ans;
	return 0;
}
// not solve
// Se giai sau
