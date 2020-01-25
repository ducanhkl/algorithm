#include <bits/stdc++.h>
#define maxn 1001
#define maxc 1e9+7

using namespace std;

double a[maxn];
double t = 0, k;
int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], t += a[i];
    int c = n;
    while (t/(double)n < k - 0.5)
        t += k, n++;
    cout << n - c;
    return 0;
}
