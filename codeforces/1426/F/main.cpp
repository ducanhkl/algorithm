#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;
const long long mod = 1e9+7;
int n;
char a[maxn];
long long f[5];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int c = a[i]-'a'+1;
        if (a[i] != '?')
        {
            f[c] =  (f[c] + f[c-1])%mod;
        } else
        {
            for (int k = 3; k >= 0; k--)
            {
                f[k]  = (f[k]*3LL)%mod;
                if (k > 0)
                    f[k] = (f[k] + f[k-1])%mod;
            }
        }
    }
    cout << f[3];
    return 0;
}
