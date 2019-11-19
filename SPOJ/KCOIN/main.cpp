#include <bits/stdc++.h>

using namespace std;

long long n, ans = 0;


int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < 60; i++)
        ans += (n>>i)&1;
    cout << pow(2, ans);
    return 0;
}
