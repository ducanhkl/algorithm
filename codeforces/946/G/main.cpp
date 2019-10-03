#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;
int n;
int a[maxn], dp1[maxn], dp2[maxn], ans = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= n; i++)
        dp1[i] = dp2[i] = INT_MAX;
    dp2[0] = dp1[0] = INT_MIN;
    int lf = 0;
    for (int i = 1; i <= n; i++)
    {
        int pos1 = upper_bound(dp1, dp1+n+1, a[i]-i+1)-dp1;
        dp1[pos1] = a[i]-i+1;
        dp1[lf] = min(dp1[lf],dp2[lf]);
        ans = max(ans, max(pos1, lf));
        lf = upper_bound(dp2, dp2+n+1, a[i]-i)-dp2;
        dp2[lf] = a[i]-i;
    }
    cout << max(n-ans-1, 0);
}
/*
7
1 5 6 2 3 4 5
*/
