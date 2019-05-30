#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    if (n <= 2*k)
        return cout << -1, 0;
    cout << n*k << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++)
            printf("%d %d \n", i, (i+j-1)%n+1);
    return 0;
}
