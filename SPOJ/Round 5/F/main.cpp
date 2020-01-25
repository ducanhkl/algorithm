#include <bits/stdc++.h>
#define maxn 100001

using namespace std;

long long a[maxn], n;

int main()
{
    for (int i = 1; i <= maxn; i++)
        a[i] = a[i-1] + i;
    cin >> n;
    bool kt = false;
    for (int i = 1; i <= maxn; i++)
        if (n - a[i] > 0)
        {
            long long k = n - a[i];
            long long x = sqrt(2*k);
            if (x*(x+1) == 2*k)
                kt =true;
        }
    if (kt)
        cout << "YES"; else cout << "NO";
    return 0;
}
