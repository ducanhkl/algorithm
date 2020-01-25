#include <iostream>

using namespace std;

long long n;
int f[2000];
int a[1000006];

int main()
{
    cin >> n;
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= 20; i++)
        f[i] = f[i-1] + f[i-2];
    for (int i = 1; i <= 20; i++)
        a[f[i]] = 1;
    for (int i = 1; i <= n; i++)
        if (a[i] == 1)
            cout << 'O';
        else cout << 'o';
    return 0;
}
