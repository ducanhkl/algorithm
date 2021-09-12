#include <iostream>

using namespace std;

const int maxn = 3e6+100;

long long dp[maxn];
int n;
const long long mod = 1e9+7;

int main()
{
//    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test = 0;
    cin >> test;

    dp[2] = 4;
    for (int i = 3; i < maxn; i++)
    {
        dp[i] = dp[i-1] + 2 * dp[i-2];
        if (i % 3 == 2)
        {
            dp[i] += 4;
        }
        dp[i] %= mod;
    }

    while (test--)
    {
        int n;
        cin >> n;
        n --;
        cout << dp[n] << endl;
    }
    return 0;
}
