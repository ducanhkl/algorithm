#include <bits/stdc++.h>

using namespace std;

int dp[5001], a[20];
int n, c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> c>> n;
    for (int i  = 1; i <= n; i++)
        cin >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = c; j >= a[i]; j--)
            if (dp[j-a[i]] == 1)
                dp[j] = 1;
    for (int j = c; j >= 0; j--)
        if (dp[j])
            return cout << j, 0;
    return 0;
}
