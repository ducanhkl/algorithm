#include <bits/stdc++.h>

using namespace std;

int n, m, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    int p = min(m, k);
    if (p < n)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}
