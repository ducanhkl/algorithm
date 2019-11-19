#include <bits/stdc++.h>

using namespace std;

long long n, ans = 0;

int main()
{
    cin >> n;
    for (int i = 0; i <= min(n, 8LL); i++)
        for (int j = 0; j <= min(n-i, 8LL); j++)
            if (i == 0 | j < 5)
                ans += n-i-j+1;
    cout << ans;
    return 0;
}
