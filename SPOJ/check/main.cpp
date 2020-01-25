#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair

using namespace std;


int nCk(int n, int k)
{
  return 1LL * fact[n] * pmod(1LL * fact[n - k] * fact[k] % MOD, MOD - 2) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    return 0;
}
