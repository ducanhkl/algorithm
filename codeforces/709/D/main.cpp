/*
#include <bits/stdc++.h>

using namespace std;

long long a, b, c, d, sl1, sl2;

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> a >> b >> c >> d;
    for (sl1 = (b+c > 0); sl1*(sl1-1) < 2*a; sl1++);
    for (sl2 = (b+c > 0); sl2*(sl2-1) < 2*d; sl2++);
    if (sl1*(sl1-1) != 2*a)
        return cout << "Impossible", 0;
    if (sl2*(sl2-1) != 2*d)
        return cout << "Impossible", 0;
    if (b+c+sl1+sl2 == 0)
        return cout << 0, 0;
    if (sl1*sl2 != b+c)
        return cout << "Impossible", 0;
    while (b+c)
        if (sl2 <= b)
    {
        b -= sl2;
        cout << 0;
        sl1--;
    } else
    {
        c -= sl1;
        cout << 1;
        sl2 --;
    }
    for (int i = 1; i <= sl1; i++)
        cout << 0;
    for (int i = 1; i <= sl2; i++)
        cout << 1;
    return 0;
}
*/
#include <bits/stdc++.h.

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= m; i++)
    {
        cin >> m[i];
        for (int j = 1; j <= m[i]; j++)
        {
            cin >> s[i][j] >> f[i][j] >> c[i][j];
            c[++cnt] = s[i][j], c[++cnt] = f[i][j];
        }
    }
    sort(c+1, c+cnt+1);
    for  (int i = 1; i <= n; i++)
        for (int j = 1; j <= m[i]; j++)
    {
        s[i][j] = lower_bound(c+1, c+cnt+1, s[i][j])-c;
        f[i][j] = lower_bound(c+1, c+cnt+1, f[i][j])-c;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m[i]; j++)

}
