#include <bits/stdc++.h>

using namespace std;

long long ans = 1;
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        ans *= 2LL;
    cout << ans-1LL;
    return 0;
}
