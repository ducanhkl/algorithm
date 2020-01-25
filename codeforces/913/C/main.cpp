#include <bits/stdc++.h>

using namespace std;

int n;
long long l, c[40];
long long ans =  4e18, cost = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 2; i <= n; i++)
        c[i] = min(c[i-1]*2, c[i]);
    for (int i = n; i >= 1; i--)
    {
        long long need = (l/(1LL<<(i-1)));
        cost += need*c[i];
        l -= need*(1LL<<(i-1));
        ans = min(ans,cost + (l>0)*c[i]);
    }
    cout << ans;
    return 0;
}
