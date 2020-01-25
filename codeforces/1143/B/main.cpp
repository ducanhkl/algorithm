#include <bits/stdc++.h>

using namespace std;

int n;
string s;
long long a[20], num[20];
long long ans[20];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> s;
    n = s.length();
    for (int i = 1; i <= n; i++)
        a[i] = s[i-1] - '0';
    num[0] = 1;
    for (int i = 1; i <= n; i++)
        num[i] = num[i-1]*9;
    memset(ans, 0, sizeof(ans));
    ans[n+1] = 1;
    for (int i = n; i >= 1; i--)
        ans[i] = max(ans[i+1]*a[i], (a[i]-1)*num[n-i]);
    cout << max(ans[1], num[n-1]);
    return 0;
}
