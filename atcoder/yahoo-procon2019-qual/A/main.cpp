#include <bits/stdc++.h>

using namespace std;

int n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    if (k <= (n+1)/2)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
