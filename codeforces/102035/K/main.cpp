#include <bits/stdc++.h>

using namespace std;

const int maxn = 2000;
int n;
int a[maxn], sum[maxn];


int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    a[1] = "1";
    sum[1] = "1";
    string mot = "1";
    for (int i = 2; i <= n; i++)
    {
        a[i] = sum[i-1]+mot;
        sum[i] = a[i] + sum[i-1];
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}
