#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

long long a[maxn], res[maxn], ans;
int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        ans = LONG_MAX;
        int pos = upper_bound(a+1, a+i+1, a[i]-90) - a;
        ans = min(ans, max(0LL, 50 - res[i-1]+res[pos-1]));
        pos = upper_bound(a+1, a+i+1, a[i]-1440) - a;
        ans = min(ans, max(0LL, 120 - res[i-1]+res[pos-1]));
        ans = min(ans, 20LL);
        cout << ans << endl;
        res[i] = ans+res[i-1];
    }
    return 0;
}
