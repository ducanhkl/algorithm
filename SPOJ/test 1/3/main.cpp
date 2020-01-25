#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("out.txt", "w", stdout);
    int ans = 0;
    int n, res;
    for (int j = 2; j <= 1000; j++)
        {
            n = j;
            ans = 0;
            for (int i = 1; i < n; i++)
                if (__gcd(n^i, n&i) > ans)
            {
                ans = __gcd(n^i, n&i);
                res = i;
            }
            cout << n << " " <<  res << " " << ans << endl;
        }
}
