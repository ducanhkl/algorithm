#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test--)
    {
        int n, x, a, b;
        cin >> n >> x >> a >> b;
        if (a > b)
            swap (a, b);
        cout << (b-a) + min(a-1+n-b, x) << endl;
    }
    return 0;
}
