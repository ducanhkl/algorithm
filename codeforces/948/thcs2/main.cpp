#include <bits/stdc++.h>
#define maxn 1000001

using namespace std;

int dd[maxn], n;

int main()
{
    cin >> n;
    for (int i = 2; i < maxn; i++)
    {
        if (!dd[i])
            for (int j = 2*i; j < maxn; j+=i)
                dd[j] = i;
        dd[i] = i-dd[i]+1;
    }
    int s = dd[n];
    for (int i = dd[n]; i <= n; i++)
        s = min(dd[i], s);
    cout << s;
    return 0;
}
