#include <iostream>
#define maxn 10005
using namespace std;

long long a[maxn], b[maxn];
long long n;

int main()
{
    a[1] = 1;
    b[0] = 0;
    for (int i = 2; i <= 40; i++)
        a[i] =  a[i-1] * 2;
    for (int i = 1;i <= 40; i++)
        b[i] = a[i] * 5;
    for (int i = 1; i <= 40; i++)
        b[i] += b[i-1];
    cin >> n;
    int d = 0;
    while (n - b[d+1] > 0) d++;
    n -= b[d];
    n = (n / a[d+1]) + (n%a[d+1]);
    cout << n;
    return 0;
}
