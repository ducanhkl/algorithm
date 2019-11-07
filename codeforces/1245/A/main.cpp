#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        int a, b;
        cin >> a >> b;
        if (__gcd(a, b) == 1)
            cout << "Finite";
        else
            cout << "Infinite";
        cout << endl;
    }
    return 0;
}
