#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;
const long long maxc = 1e18+1;
int n;
long double ans = 0, tt = 0,a[maxn], res = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], ans = max(ans, a[i]);
    for (int i =1 ; i <= n; i++)
        if (a[i] == ans)
            tt++;
        else
        {
            res = max(res, tt);
            tt = 0;
        }
    res = max(res, tt);
    cout << res;
    return 0;
}
