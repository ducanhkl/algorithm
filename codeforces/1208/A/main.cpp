#include <bits/stdc++.h>

using namespace std;

void solve(int n, long long x, long long y)
{
    int b[50];
    int c[] = {1, 1, 0};
    for (int i = 0; i <= 40; i++)
    {
        b[i] = 0;
        int b1 = (x>>i)&1;
        int b2 = (y>>i)&1;
        if (b1 == 0 && b2 == 0)
        {
            b[i] = 0;
            continue;
        }
        if (b1 == 0 && b2 == 1)
        {
            b[i] = c[(n+2)%3];
            continue;
        }
        if (b1 == 1 && b2 == 0)
        {
            b[i] = c[(n+1)%3];
            continue;
        }
        if (b1 == 1 && b2 == 1)
        {
            b[i] = c[n%3];
        }
    }
    long long res = 0;
    for (int i = 40 ;i >= 0; i--)
        res = (res*2LL+b[i]);
    cout << res << endl;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    long long n, a, b;
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        cin >>a >> b >> n;
        solve(n, a, b);
    }
    return 0;
}
