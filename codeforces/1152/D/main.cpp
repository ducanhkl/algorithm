#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;
const int maxn = 1e3+100;

int n;
long long f[maxn][maxn], res = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(f, 0, sizeof(f));
    ios_base::sync_with_stdio(false);
    cin >> n;
    f[1][1] = 1;
    for (int i = 2; i <= n+1; i++)
      for (int j = 1; j <= i; j++)
      {
          f[i][j] = (f[i-1][j]+f[i][j-1])%mod;
          res = (res+((i+j)%2)*f[i][j])%mod;
      }
    cout << res;
    return 0;
}
