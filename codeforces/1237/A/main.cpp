#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5;
int sum = 0;
int a[maxn];
int n;

int getup(int x)
{
    return (x+1)/2;
}

int getdown(int x)
{
    return (x-1)/2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] % 2 == 0)
        {
            sum += a[i]/2;
        } else
        {
            sum += getup(a[i]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % 2 == 0)
        {
            cout << a[i]/2 << endl;
            continue;
        }
        if (sum > 0)
        {
            cout << getdown(a[i]) << endl;
            sum --;
        } else
        cout << getup(a[i]) << endl;
    }

    return 0;
}
