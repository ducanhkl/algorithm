#include <bits/stdc++.h>

using namespace std;

long long n, m;

class matrix
{
    public:
        long long a[5][5];
    void reset()
    {
        memset(a, 0, sizeof(a));
    }
};

matrix operator * (matrix x, matrix y)
{
    matrix z;
    z.reset();
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            for (int k = 1; k <= 3; k++)
                z.a[i][j] = (z.a[i][j] + x.a[i][k]*y.a[k][j])%m;
    return z;
}
matrix fast_pow(matrix x, int y)
{
    if (y == 1)
        return x;
    matrix c = fast_pow(x, y/2);
    if (y%2)
        return (x*c*c);
    else return (c*c);
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    if (n == 1)
        return cout << 1%m, 0;
    if (n == 2)
        return cout << 2%m, 0;
    if (n == 3)
        return cout << 4%m, 0;
    matrix k;
    k.reset();
    k.a[2][1] = k.a[3][2] = k.a[1][3] = k.a[2][3] = k.a[3][3] = 1;
    matrix b = fast_pow(k, n-3);
    cout << (b.a[1][3] + b.a[2][3]*2 + b.a[3][3]*4)%m;
    return 0;
}
