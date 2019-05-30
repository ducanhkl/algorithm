#include <bits/stdc++.h>
#define maxn 5009

using namespace std;

int n, a[maxn];
int res = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 5; i <= n-5; i++)
    {
        int len = 1;
        for (int j = n; j > i; j--)
            if (a[j] - a[j-1] == a[j-i] - a[j-i-1])
                    {
                        len ++, res = max(res, len);
                        if (len == i)
                            break;
                    }
            else len = 1;
    }
    if (res < 5)
        return cout << 0, 0;
    cout << res;
    return 0;
}
