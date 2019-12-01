#include <bits/stdc++.h>

using namespace std;

long long r, b, k;

int main()
{
    //freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while(test--)
    {
        cin >> r >> b >> k;
        if (r > b)
            swap(r, b);
        if (b % r == 0)
        {
            int t = b/r - 1;
            if (t >= k)
            {
                cout << "REBEL";
            } else
            {
                cout << "OBEY";
            }
        } else
        {
            long long t = b/r;
            long long l = __gcd(r, b);
            if (b - l > r*t)
                t++;
            if (t >= k)
            {
                cout << "REBEL";
            } else
            {
                cout << "OBEY";
            }
        }
        cout << endl;
    }
    return 0;
}
