#include<bits/stdc++.h>
using namespace std;
#define gt getchar()
#define ll long long
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
inline int in(){int k;scanf("%d",&k);return k;}
const int N=8e5+5,YL=1e9+7;
int a[N],b[N];
inline void cmax(int &x,int y){if(x<y)x=y;}
inline void cmin(int &x,int y){if(x>y)x=y;}
inline int ksm(int a,int k){int r=1;while(k){if(k&1)r=1ll*r*a%YL;a=1ll*a*a%YL,k>>=1;}return r;}
bitset<70>bj[N<<2],fz[500],lzx[N<<2],t;
int sum[N<<2],np[N],pr[N],tot,lz[N<<2];
char ch[N];
#define lc k<<1
#define rc k<<1|1
inline void pushup(int k)
{
	bj[k]=bj[lc]|bj[rc];
	sum[k]=1ll*sum[lc]*sum[rc]%YL;
}
inline void pushdown(int l,int r,int k)
{
	if(lz[k]!=1)
	{
		int mid=l+r>>1,L=mid-l+1,R=r-mid;
		lz[lc]=1ll*lz[lc]*lz[k]%YL;
		lz[rc]=1ll*lz[rc]*lz[k]%YL;
		sum[lc]=1ll*sum[lc]*ksm(lz[k],L)%YL;
		sum[rc]=1ll*sum[rc]*ksm(lz[k],R)%YL;
		bj[lc]|=lzx[k],bj[rc]|=lzx[k];
		lzx[lc]|=lzx[k],lzx[rc]|=lzx[k];
		lz[k]=1;lzx[k].reset();
	}
}
void build(int l,int r,int k)
{
	int mid=l+r>>1;lz[k]=1;
	if(l==r)return bj[k]=fz[a[l]],sum[k]=a[l],void();
	build(l,mid,lc),build(mid+1,r,rc);pushup(k);
}
void upd(int L,int R,int l,int r,int k,int ad)
{
	if(L<=l&&r<=R)
	{
		lz[k]=1ll*lz[k]*ad%YL;
		sum[k]=1ll*sum[k]*ksm(ad,(r-l+1))%YL;
		bj[k]|=fz[ad],lzx[k]|=fz[ad];
		return;
	}
	int mid=l+r>>1;
	pushdown(l,r,k);
	if(L<=mid)upd(L,R,l, mid ,lc,ad);
	if(R> mid)upd(L,R,mid+1,r,rc,ad);
	pushup(k);
}
void query(int L,int R,int l,int r,int k,int &ans,bitset<70> &t)
{
	if(L<=l&&r<=R)return ans=1ll*ans*sum[k]%YL,t|=bj[k],void();
	int mid=l+r>>1;pushdown(l,r,k);
	if(L<=mid)query(L,R,l, mid ,lc,ans,t);
	if(R> mid)query(L,R,mid+1,r,rc,ans,t);
}
int main()
{
    freopen("inp.txt", "r", stdin);
	int n=in(),q=in();
	for(int i=1;i<=n;++i)a[i]=in();
	for(int i=2;i<=300;++i)
	{
		if(!np[i])pr[++tot]=i,fz[i][tot]=1;
		for(int j=1;i*pr[j]<=300&&j<=tot;++j)
		{np[i*pr[j]]=1;fz[i*pr[j]]=fz[i]|fz[pr[j]];if(i%pr[j]==0)break;}
	}
	build(1,n,1);
	while(q--)
	{
		scanf("%s",ch+1);
		int l=in(),r=in();
		if(ch[1]=='T')
		{
			t.reset();int ans=1;
			query(l,r,1,n,1,ans,t);
			for(int i=1;i<=tot;++i)
				if(t[i])ans=1ll*ans*ksm(pr[i],YL-2)%YL*(pr[i]-1)%YL;
			printf("%d\n",ans);
		}
		else upd(l,r,1,n,1,in());
	}
	return 0;
}
