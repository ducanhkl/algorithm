#include <bits/stdc++.h>
#define MAXNUM 1000000007
using namespace std;

int n, a[100001];
long long ans = 1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    for (int i = 0; i < n; i++)
        ans = (ans*(a[i] - i))%MAXNUM;
    cout << ans;
    return 0;
}
