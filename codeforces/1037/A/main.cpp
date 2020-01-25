#include <bits/stdc++.h>

using namespace std;

long long n, ans = 0, dem = 0, res = 0;

int main()
{
    cin >> n;
    while (ans < n)
    {
        ans += ans + 1;
        res ++;
    }
    cout << res;
    return 0;
}
