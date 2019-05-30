#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
    cin >> n;
    if (n == 1 || n == 2)
        return cout << "No", 0;
    int res = (n+1)/2;
    cout << "Yes" << endl;
    cout << 1 << " " << res << endl;
    cout << n-1;
    for (int i = 1; i < res; i++)
        cout << " " << i;
    for (int i = res+1; i <= n; i++)
        cout << " " << i;
    return 0;
}
