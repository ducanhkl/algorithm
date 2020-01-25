
#include <bits/stdc++.h>
#define reset(x) memset(x, 0, sizeof(x))
#define MOD 210

using namespace std;

long long a[300], f[70][300], d[70][300], ans = 0;
int n;

void init()
{
    reset(a);
    reset(f);
    reset(d);
    ans = 0;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t, dem = 0;
    cin >> t;
    while (t --)
    {
        init();
        string s;
        cin >> s;
        n = s.length();
        for (int i = 0; i < s.length(); i++)
            a[i+1] = (int)(s[i] - '0');
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
                d[i][j] = (d[i][j-1]*10+a[j])%MOD;
        f[0][0] = 1;
        for (int i = 0; i <= n; i++)
            for (int k = 0; k < MOD; k++)
                for (int j = i+1; j <= n; j++)
            {
                f[j][(k+d[i+1][j])%MOD] += f[i][k];
                if (i != 0)
                    f[j][(k-d[i+1][j]+MOD)%MOD] += f[i][k];
            }
        for (int i = 0; i < MOD; i++)
            if (i%2== 0 || i%3 ==0 || i%5 == 0 || i%7 == 0)
                ans += f[n][i];
        cout << "Case #" << ++dem << ": " << ans << endl;
    }
    return 0;
}
