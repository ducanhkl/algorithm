#include <bits/stdc++.h>
#define maxn 401

using namespace std;


int n;
int f[maxn], a[maxn][maxn];
long long ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(a, 0, sizeof(a));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        a[x+200][y+200] = 1<<(c-1);
    }
    for (int i = 0; i <= 400; i++)
        for (int j = 0; j <= i; j++)
            {
                memset(f, 0, sizeof(f));
                for (int k = 0; k <= 400; k++)
                    if (a[i][k] && a[j][k] && a[i][k] != a[j][k])
                {
                    int t = a[i][k] | a[j][k];
                    ans += f[15-t];
                    f[t]++;
                }
            }
    cout << ans;
    return 0;
}
