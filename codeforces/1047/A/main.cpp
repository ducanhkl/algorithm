#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i<= n; i++)
        for (int j = 1; j <= n-i; j++)
    {
        int k = n-i -j;
        if (k == 0)
            continue;
        if (i%3 == 0 || j %3 == 0 || k%3 == 0)
            continue;
        cout << i << " " << j << " " << k;
        return 0;
    }
    return 0;
}
