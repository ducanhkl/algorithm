#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;
long long l, r;
unsigned long long p[100];


long long get1(long long pos)
{
    return pos*pos%mod;
}

long long get2(long long pos)
{
    return (pos*(pos+1)%mod)%mod;
}

long long calc(long long pos)
{
    unsigned long long value = 0;
    int vt = 0;
    for (int i = 0; i <= 64; i++)
    {
        value += p[i];
        if (value > pos)
        {
            value -= p[i];
            vt = i;
            break;
        }
    }
    unsigned long long even = 0, odd = 0;
    for (int i = 0; i < vt; i++)
        if (i%2)
            even += p[i];
        else
            odd += p[i];
    if (vt%2)
        even += (pos-value);
    else
        odd += (pos-value);
    return (get1(odd%mod) + get2(even%mod))%mod;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    p[0] = 1;
    for (int i = 1; i <= 64; i++)
        p[i] = p[i-1]*2LL;
    ios_base::sync_with_stdio(false);
    cin >> l >> r;
    long long res1 = calc(r);
    long long res2 = calc(l-1);
    cout << (res1-res2+mod)%mod;
    return 0;
}
