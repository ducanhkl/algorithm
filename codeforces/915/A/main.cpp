#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, k;
int a[maxn];

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = n; i >= 1; i--)
        if (k % a[i] == 0)
            return cout << k/a[i], 0;
    return 0;
}
