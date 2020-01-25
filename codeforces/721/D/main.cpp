#include <bits/stdc++.h>
#define maxn 550005

using namespace std;

long long _f1[4*maxn], _f2[4*maxn];
long long *f1 = _f1+maxn, *f2 = _f2+maxn, ans = 0;
int a, b, k, n;
const long long mod = 1e9+7;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> k >> n;
    f1[0] = 1;
    for (int i = 1; i <= 2*n; i++)
    {
        memset(f2, 0, sizeof(f2));
        for (int j = -2*k*n; j <= 2*k*n; j++)
            f1[j] = (f1[j-1] + f1[j])%mod;
        for (int j = -2*k*n; j <= 2*k*n; j++)
            f2[j] = (f1[min(j+k, 2*k*n)] - f1[max(j-k-1, -2*k*n-1)]+2*mod)%mod;
        /*
        cout << i << endl;
        for (int j = -k*n; j <= k*n; j++)
            cout << f2[j] << " ";
        cout << endl;
        */
        swap(f1, f2);
    }
    for (int i = b+1-a; i <= 2*k*n; i++)
        ans = (ans+f1[i])%mod;
    cout << ans;
}
