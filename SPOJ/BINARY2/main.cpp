#include <bits/stdc++.h>
#define MOD 1000000000
#define maxn 1000006

using namespace std;

int n, k;
long long res, a[maxn];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    a[1] = res = 2;
    for (int i = 2; i <= n+1; i++)
    {
        a[i] = res;
        res = (a[i] + res)%MOD;
        if (i - k > 0)
            res = (res-a[i-k]+MOD)%MOD;
    }
    cout << a[n+1]%MOD;
    return 0;
}
