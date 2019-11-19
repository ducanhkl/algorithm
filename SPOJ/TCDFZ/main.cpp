#include <bits/stdc++.h>

using namespace std;

int n;
int res[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
int calc(int x)
{
    if (x < 10)
        return res[x];
    if (((x/10)%10)%2 == 0)
        return (6*calc(x/5)*res[x%10])%10;
    else return ((4*calc(x/5)*res[x%10]) % 10);
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    cout << calc(n);
    return 0;
}
