#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test --)
    {
        int n, a[200];
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = n; i >= 1; i--)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}
