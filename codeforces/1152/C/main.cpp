#include <bits/stdc++.h>

using namespace std;

typedef pair <long long, long long> pii;

long long a, b;
pii ans;

void check(long long value)
{
    long long tmp = value - a%value;
    long long lcm = (a+tmp)*(b+tmp)/__gcd(a+tmp, b+tmp);
    ans = min(ans, (pii){lcm, tmp});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    ans = {a*b/__gcd(a, b), 0};
    for (int i = 1; i*i <= abs(a-b); i++)
        if (abs(a-b)%i == 0)
    {
        check(abs(a-b)/i);
        check(i);
    }
    cout << ans.second;
    return 0;
}
