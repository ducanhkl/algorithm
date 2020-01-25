#include <bits/stdc++.h>

using namespace std;

long long n, t1, t2, t3, t4;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    t1 = n/100;
    n -= t1*100;
    t2 = n/20;
    n -= t2*20;
    t3 = n/10;
    n -= t3*10;
    t4 = n/5;
    n -= t4*5;
    cout << t1 + t2 + t3 + t4 + n;
    return 0;
}
