#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        long long a
        cin >> a >> b >> c;
        cout << max(a, max(b, c)) + 1 << endl;
    }
    return 0;
}
