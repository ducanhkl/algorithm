#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    ios_base::sync_with_stdio(false);
    while (cin >> a >> b >> c)
    {
        if (b - a < c - b)
            cout << c - b -1;
        else cout << b-a - 1;
        cout << endl;
    }
    return 0;
}
