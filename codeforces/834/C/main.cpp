#include <bits/stdc++.h>
using namespace std;

long long a, b,l, r;
int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    scanf("%d", &n);
    while (n --)
    {
        scanf("%d%d", &a, &b);
        r = ceil(cbrt(a*b));
        puts((r*r*r==a*b&&a%r==0&b%r==0?"YES":"NO"));
    }
}
