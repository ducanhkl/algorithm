#include <bits/stdc++.h>

using namespace std;


long long a, b, c;
long long rr, res;

int main()
{
    long long test;
    cin >> test;
    while (test--)
    {
        cin >> a >> b >> c;
        if (a > c)
            swap(a, c);
        if (b > c)
            swap(b, c);
        if (a > b)
            swap(a, b);
        rr = c-b;
        long long res = min(rr, a);
        a -= res;
        res += min(b-a/2, c-a/2) + 2*(a/2);
        cout << res << endl;
    }
    return 0;
}
