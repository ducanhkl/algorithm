#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<cctype>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define int long long
using std::min;
using std::max;
using std::swap;
using std::vector;
const int N=5e5+5;
typedef double db;
const int mod=1e9;
typedef long long ll;
#define pb(A) push_back(A)
#define pii std::pair<int,int>
#define mp(A,B) std::make_pair(A,B)

int n;
ll qz[N][2];
ll mn[N][2];
ll mx[N][2];
ll val[N],ans;
int stk[N],top;

int qh(int l,int r){
    if(l>r)
        return 0;
    int len=r-l+1;
    return (l+r)*len/2%mod;
}

int getint(){
    int X=0,w=0;char ch=0;
    while(!isdigit(ch))w|=ch=='-',ch=getchar();
    while( isdigit(ch))X=X*10+ch-48,ch=getchar();
    if(w) return -X;return X;
}
const int inf=1e9;
void solve(int l,int r){
    if(l==r)
    {
        (ans+=val[l]*val[l]%mod)%=mod;
        return;
    }
    int mid=l+r>>1;
    solve(l,mid);
    solve(mid+1,r);
    ll minn=inf,maxn=-inf;
    qz[mid][0]=qz[mid][1]=0;
    for(int i=mid+1;i<=r;i++)
    {
        minn=min(minn,val[i]);
        maxn=max(maxn,val[i]);
        mn[i][0]=(mn[i-1][0]+minn)%mod;
        mn[i][1]=(mn[i-1][1]+minn*(i-mid)%mod)%mod;
        mx[i][0]=(mx[i-1][0]+maxn)%mod;
        mx[i][1]=(mx[i-1][1]+maxn*(i-mid)%mod)%mod;
        qz[i][0]=(qz[i-1][0]+(ll)minn*maxn%mod)%mod;
        qz[i][1]=(qz[i-1][1]+(ll)minn*maxn%mod*(i-mid)%mod)%mod;
    }
    minn=inf,maxn=-inf;
    int p=mid+1,q=mid+1;
    for(int i=mid;i>=l;i--)
    {
        minn=min(minn,val[i]);
        maxn=max(maxn,val[i]);
        while(p<=r and val[p]>=minn)
            p++;
        while(q<=r and val[q]<=maxn)
            q++;
        int lll=min(p,q),rr=max(p,q);
        int len=lll-mid-1;
        (ans+=qh(mid+1-i+1,lll-1-i+1)*maxn%mod*minn%mod)%=mod;
        if(p<q) (ans+=(mn[q-1][1]-mn[p-1][1]+mod)%mod*maxn%mod+(mn[q-1][0]-mn[p-1][0]+mod)%mod*(mid-i+1)%mod*maxn%mod)%=mod;
        if(p>q) (ans+=(mx[p-1][1]-mx[q-1][1]+mod)%mod*minn%mod  +(mx[p-1][0]-mx[q-1][0]+mod)%mod*(mid-i+1)%mod*minn%mod)%=mod;
        (ans+=(qz[r][1]-qz[rr-1][1]+mod)%mod+(qz[r][0]-qz[rr-1][0]+mod)%mod*(mid-i+1)%mod)%=mod;
    }
}

signed main(){
    n=getint();
    for(int i=1;i<=n;i++) val[i]=getint();
    solve(1,n);
    printf("%lld\n",ans);
    return 0;
}