#include <bits/stdc++.h>

using namespace std;

long long calc(long long x, long long y, int z)
{
    if (z == 1)
        return x+y;
    if (z == 2)
        return x*y;
    if (z == 3)
        return x-y;
}
bool check;

void solve(long long a, long long b, long long c, long long d, long long e)
{
    for (int i = 1; i <= 3 && check; i++)
            for (int j = 1; j <= 3 && check; j++)
                for (int k = 1; k <= 3 && check; k++)
                    for (int h = 1; h <= 3 && check; h ++)
        {
            long long tt = calc(calc(calc(calc(a, b, i), c, j), d, k), e, h);
            if (calc(calc(calc(calc(a, b, i), c, j), d, k), e, h) == 23)
            {
                check = false;
                return;
            }
        }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int t;
    //ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        check = true;
        int a[6], b[6], c[6];
        for (int i = 1; i <= 5; i++)
            cin >> a[i], c[i] = i;
        for (int i = 1; i <= 5; i++)
            b[i] = a[c[i]];
        solve(b[1], b[2], b[3], b[4], b[5]);
        while (next_permutation(c+1, c+5+1))
        {
            for (int i = 1; i <= 5; i++)
                b[i] = a[c[i]];
            solve(b[1], b[2], b[3], b[4], b[5]);
        }
        if (check)
            cout << "NO";
        else
            cout << "YES";
        cout << endl;
    }
    return 0;
}

