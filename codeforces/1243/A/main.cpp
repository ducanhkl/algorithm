#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e3+100;

int ans = 0;
int n, a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= 1000; i++)
        {
            int cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                if (a[j] >= i)
                    cnt ++;
            }
            if (cnt >= i)
            {
                ans = i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
