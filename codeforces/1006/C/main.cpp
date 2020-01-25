#include <bits/stdc++.h>
#define maxn 200006

using namespace std;

int n;
long long a[maxn], res = 0, ans = 0, tt = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int r = n+1;
    for (int i = 1; i <= n; i++)
    {
        ans += a[i];
        while (ans > tt && r-1 > i)
            tt += a[--r];
        if (ans == tt)
            {
                res = ans;
                continue;
            }
        if (r <= i)
            break;
    }
    cout << res;
    return 0;
}
