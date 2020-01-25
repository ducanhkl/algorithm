#include <bits/stdc++.h>
#define ma 1e18

using namespace std;

unsigned long long l, r, a[1050000];
int q, n;

void init()
{
    for(long long i=2;i*i*i<=ma;i++)
    {
        for(long long j=i;j<=ma/(i*i);j*=(i*i))
        {
            long long temp=sqrt(j*i*i);
            if(temp*temp!=j*i*i)
                a[n++]=j*i*i;
        }
    }
    sort(a+1, a+n);
    n = unique(a, a+n)-a;
}

long long calc(long long x)
{
    if (x == 0)
        return 0;
    return (long long)sqrt(x) + (long long)(upper_bound(a, a+n, x) - a);
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    init();
    cin >> q;
    while (q--)
    {
        int dem = 0;
        cin >> l >> r;
        cout << calc(r) - calc(l-1) << endl;
    }
    return 0;
}
