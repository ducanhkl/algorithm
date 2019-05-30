#include <bits/stdc++.h>

using namespace std;

int dp[2001][2001], k;
string s1, s2;
int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> s1 >> s2 >> k;
    s1 = " " + s1;
    s2 = " " + s2;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < 2001; i++)
        dp[i][0] = i*k, dp[0][i] = i*k;
    for (int i = 1; i < s1.length(); i++)
        for (int j = 1; j < s2.length(); j++)
            dp[i][j] = min(min(dp[i][j-1], dp[i-1][j])+k, dp[i-1][j-1]+abs(s1[i] - s2[j]));
    cout << dp[s1.length()-1][s2.length()-1];
    return 0;
}
