#include <bits/stdc++.h>
#define maxn 300000

using namespace std;

long long a[maxn];
int n, k, ans;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t, CASE = 1;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        memset(a, 0, sizeof(a));
        ans = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a+1, a+n+1);
        for (int i = 1; i <= n; i++)
        {
            int pos = lower_bound(a+1, a+i+1, a[i] - k) - a;
            ans = max(ans, i-pos+1);
        }
        cout << "Case #" << CASE++ << endl;
        cout << ans << endl;
    }
    return 0;
}
