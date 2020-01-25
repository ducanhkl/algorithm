#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005

using namespace std;

ll ans, n;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(false);
    cin >> n;
    for (int i = 1; i <=9; i++)
    {
        ll k = ((1<<i)-1)*(1<<(i-1));
        if (n%k == 0)
            ans = max(ans, k);
    }
    cout << ans;
    return 0;
}
