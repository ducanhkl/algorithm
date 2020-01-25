#include <bits/stdc++.h>

using namespace std;

int a[100000];
int k, dem = 0;

bool check (int x)
{
    int tong = 0;
    while (x!=0)
    {
        tong += x%10;
        x/=10;
    }
    return tong == 10;
}
int main()
{
    cin >> k;
    int i = 0;
    while(++i)
    {
        if (check(i))
            a[++dem] = i;
        if (dem == 10000)
            break;
    }
    cout << a[k];
    return 0;
}
