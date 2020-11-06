#include<bits/stdc++.h>
using namespace std;
#define N 100001
#define LL long long
LL n,p,k,f[N][128];
struct rua
{
    LL v,s[8];
    bool operator <(const rua &t)const
    {
        return v>t.v;
    }
} a[N];
int main()
{
    memset(f,172,sizeof(f));
    scanf("%lld%lld%lld",&n,&p,&k);
    for(LL i=1; i<=n; i++)scanf("%lld",&a[i].v);
    for(LL i=1; i<=n; i++)for(LL j=0; j<p; j++)scanf("%lld",&a[i].s[j]);
    sort(a+1,a+n+1),f[0][0]=0;
    for(LL i=1; i<=n; i++)
        for(LL b=0,cnt=0; b<(1<<p); b++,cnt=0)
        {
            for(LL k=0; k<p; k++)if((1ll<<k)&b)
                    cnt++,f[i][b]=max(f[i][b],f[i-1][(1ll<<k)^b]+a[i].s[k]);
            f[i][b]=max(f[i][b],f[i-1][b]+(i<=cnt+k?a[i].v:0));
        }
    printf("%lld\n",f[n][(1<<p)-1]);
//JSR
}
