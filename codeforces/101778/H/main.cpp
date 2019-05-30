#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
char a[maxn];
int n, m;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        int cnt = 0, ans = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i < (n+1)/2; i++)
            if (a[i] != a[n-i+1])
                cnt++;
        for (int i = 1; i <= m; i++)
        {
            int p;
            char x;
            cin >> p >> x;
            if (a[p] != a[n-p+1] && x == a[n-p+1])
                cnt--;
            if (a[p] == a[n-p+1] && x != a[n-p+1])
                cnt++;
            if (cnt == 0)
                ans ++;
        }
        cout << ans << endl;
    }
    return 0;
}
