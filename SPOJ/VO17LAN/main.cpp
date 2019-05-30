#include <bits/stdc++.h>
#define maxn 100005

using namespace std;


int n, t;
int a[maxn], ans = 0;


void check(int x)
{
    if (x < ans)
        return;
    int t1 = x, t2 = 0;

    for (int i = 2; i <= n; i++)
        {
            if (a[i]%x == 0)
                t1 = __gcd (t1, a[i]);
            else
                if (t2 == 0)
                    t2 = a[i];
                else t2 = __gcd (a[i], t2);
            if (t2 && min (t1, t2) < ans)
                return;
        }
    if (t2 == 0)
        t2 = t1;

    ans = max (ans, min (t1, t2));

    return;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> t;

    while (t--)
    {
        ans = 0;

        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        sort (a+1, a+n+1);

        for (int i = sqrt(a[1]); i >= 1; i--)
            if (a[1]%i == 0)
        {
            check (i);
            check (a[i]/i);
        }

        cout << ans << endl;
    }
    return 0;
}
