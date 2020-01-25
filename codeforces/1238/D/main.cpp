#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;

long long n, ans = 0, cnt = 0, len = 0;
int b[maxn];
char a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cnt = 1;
    len = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] != a[i-1])
            b[len++] = cnt, cnt = 1;
        else
            cnt++;
    }
    b[len] = cnt;
    ans = (n*(n-1))/2;
    for  (int i = 1; i < len; i++)
        ans -= b[i] + b[i+1] - 1;
    cout << ans;
    return 0;
}
