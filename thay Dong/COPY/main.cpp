#include <bits/stdc++.h>
#define maxn 1000006
#define input "COPY.INP"
#define output "COPY.OUT"

using namespace std;

int n;
long long a[maxn], w;
int main()
{
    freopen(input, "r", stdin);
    freopen(output, "w", stdout);
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort (a+1, a+n+1);
    for (int i = 1; i <= n; i++)
        a[i] += a[i-1];
    for (int i = 1; i <= n; i++)
        if (a[i] > w)
            return cout << i-1, 0;
    return 0;
}
