#include <bits/stdc++.h>

using namespace std;


long double c(int y, int x)
{
    long double res = 1;
    if (x < y)
        return 0;
    for (int i = x; i> x-y; i--)
        res = res * i;
    for (int i = 1; i <= y; i++)
        res = res/i;
    return res;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    int n;
    string s;
    while (cin >> s)
    {
        if (s == "[END]")
            return 0;
        cin >> n;
        long double x = c(5, n)*3125 + c(3, n-1)*1250*n + c(2, n-1)*500*n;
        long double y = c(5, 5*n);
        long double res;
        if (x == 0)
            res = 0;
        else res = x/y;
        cout << fixed << setprecision(10) << (long double)1.0-res << endl;
    }
    return 0;
}
