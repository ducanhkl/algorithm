#include <iostream>
#define maxc 63

using namespace std;

long long m;
int k;
long long c[maxc+10][maxc+10];

long long counter(long long x)
{
    int _k = k;
    long long res = (int)(__builtin_popcountll(x) == k);
    for (int i = maxc; i >= 0; i--)
    {
        if ((x>>i)&1 && i >= _k && _k >= 0)
            res += c[i][_k--];
    }
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    for (int i = 0; i < maxc; i++)
        c[i][0] = 1;
    for (int i = 0; i <= maxc; i++)
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    ios_base::sync_with_stdio(false);
    cin >> m >> k;
    long long l = 1, r = 1e18;
    while (l <= r)
    {
        long long mid = (l+r)>>1;
        if (mid == 909493)
            m = m;
        long long p1 = counter(2LL*mid);
        long long p2 =  counter(mid);
        long long res = p1-p2;
        if (res == m)
        {
            cout << mid;
            return 0;
        }
        if (res > m)
            r = mid-1;
        else
            l = mid+1;
        if (l != 0)
            m = m;
    }
    return 0;
}
