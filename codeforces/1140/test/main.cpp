#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ans = 0, a, b;
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
        for (int j = 1;j <= b; j++)
            if (__gcd(i, j) == 1)
                {
                    cout << i << " " << j << endl;
                    ans ++;
                }
    cout << ans;
    return 0;
}
