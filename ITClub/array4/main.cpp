#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 1000000007
#define maxn 1000005
using namespace std;

ll ans = 0, n;

ll p[maxn];


void init()
{
    p[0] = 1;
    p[1] = 1;
    for (int i = 2; i <= n; i++)
        {
            p[i] = p[i-1] * i;
            p[i] = p[i]%maxnum;
        }
}

ll fast_pow(long long base, long long n,long long M)
{
    if(n==0)
       return 1;
    if(n==1)
    return base;
    long long halfn=fast_pow(base,n/2,M);
    if(n%2==0)
        return ( halfn * halfn ) % M;
    else
        return ( ( ( halfn * halfn ) % M ) * base ) % M;
}
ll findMMI_fermat(ll n,ll M)
{
    return fast_pow(n,M-2,M);
}

ll tinh(int x, int y)
{
    ll k = findMMI_fermat((p[y] * p[x-y])%maxnum, maxnum);
    return (p[x]*k)%maxnum;
}
int main()
{
    //freopen("inp.ttx", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	init();
	for (ll i = 1; i <= n; i++)
        {
            ans += tinh(n-1, i-1)*tinh(n, i);
            ans = ans % maxnum;
        }
    cout << (2*ans-n)%maxnum;
	return 0;
}
