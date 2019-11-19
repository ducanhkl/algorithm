#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("out.txt", "w", stdout);
    int n = 2*1e9+1;
    for (int i = 2; i <= n; i++)
        {
            for (int j = 2; j < sqrt(i); j++)
                if (i%j == 0)
                    break;
        }
    return 0;
}
