#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;

long long n, k, s, vt = 0;
long long dd[maxn], f[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n >> k >> s;
    f[1] = 1%k;
    f[2] = 1%k;
    for (int i = 3; i <= n; i++)
    {
        f[i] = (f[i-1]+f[i-2])%k;
        if (f[i] == f[2] && f[i-1] == f[1])
        {
            vt = i-2;
            break;
        }
    }
    if (vt == 0)
    {
        sort(f+1, f+n+1);
        cout << f[s];
        return 0;
    }
    long long a = n/vt;
    long long _a = n%vt;
    for (int i = 1; i <= vt; i++)
        dd[f[i]] += a;
    for (int i = 1; i <= _a; i++)
        dd[f[i]] += 1;
    vt = 0;
    while (s > dd[vt])
    {
        s -= dd[vt];
        vt ++;
    }
    cout << vt;
    return 0;
}
