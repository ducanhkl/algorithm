#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 10000007

using namespace std;

ll dd[maxn+10], d[maxn+10], snt[maxn+10];
int n;

void init()
{
    for (int i = 2; i <= maxn; i++)
        {
            d[i-1] += d[i-2];
            if (snt[i] == 0)
                {
                    d[i] = dd[i];
                    for (int j = 2*i; j < maxn; j += i)
                    {
                        snt[j] = 1;
                        d[i] = dd[j] + d[i];
                    }
                }
        }
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt","w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        dd[x] ++;
    }
    init();
    /*for (int i = 1; i < maxn; i++)
        d[i] += d[i-1];*/
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        int l, r;
        scanf("%d%d",&l,&r);
        l = min(maxn-1, l);
        r = min(maxn-1, r);
        printf("%d\n", d[r]-d[l-1]);
    }
	return 0;
}
