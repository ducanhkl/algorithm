#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

int n;
int a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    cout << a[n] - a[1] + 1 - n;
    return 0;
}
