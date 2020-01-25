#include <bits/stdc++.h>

using namespace std;


long long n;

const long long mod = 1e15+7;

class matrix
{
public:
    long long a[10][10];
    int n;
    void reset()
    {
        memset(a, 0, sizeof(a));
    }
};

matrix xx;

long long mul(long long a, long long b)
{
    if (a == 0 || b == 0)
        return 0;
    if (b == 1)
        return a%mod;
    if (a == 1)
        return b%mod;
    long long res = mul(a, b/2);
    if (b%2)
        return (res*2%mod+a)%mod;
    return res*2%mod;
}

matrix operator * (matrix a, matrix b)
{
    matrix res;
    res.reset();
    for (int i = 1; i <= a.n; i++)
        for (int j = 1; j <= b.n; j++)
            for (int k = 1; k <= a.n; k++)
                res.a[i][j] = (res.a[i][j] + mul(a.a[i][k], b.a[k][j]))%mod;
    res.n = 4;
    return res;
}

matrix fast_pow(matrix x, long long y)
{
    if (y == 1)
        return x;
    matrix res = fast_pow(x, y/2);
    res = res*res;
    if (y%2)
        return res*x;
    return res;
}

long long calc()
{
    if (n <= 3)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 3;
        if (n == 3)
            return 6;
    }
    matrix res = fast_pow(xx, n-3);
    return (res.a[3][1] + res.a[3][2]*3%mod+res.a[3][3]*6%mod+res.a[3][4]*2%mod)%mod;
}


int main()
{
    //freopen("inp.txt", "r", stdin);
    xx.n = 4;
    xx.reset();
    xx.a[1][2] = xx.a[2][3] = xx.a[3][1] = xx.a[3][2] = xx.a[3][3] = xx.a[3][4] = xx.a[4][4] = 1;
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        cout << calc() << endl;
    }
    return 0;
}
