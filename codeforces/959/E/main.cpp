#include <bits/stdc++.h>

using namespace std;

long long n, ans = 0;


int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    n--;
    for (long long i = 1; i <= n; i *= 2LL)
        ans += ((n-i)/(2*i)+1)*i;
    cout << ans;
    return 0;
}
