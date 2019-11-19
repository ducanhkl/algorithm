#include <bits/stdc++.h>

using namespace std;

long long ans = 0;
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 2; 2*i <= n; i++)
        for (int j = 2*i; j <= n; j+=i)
    {
        ans += (long long)j/i;
    }
    cout << ans*4LL;
    return 0;
}
