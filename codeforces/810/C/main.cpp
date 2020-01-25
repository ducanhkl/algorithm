#include <bits/stdc++.h>
#define maxn 1001

using namespace std;

vector <long long> a;
vector <long long> counts;
int n;
long long c = 1, t = 0;
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        a.push_back(x);
        counts.push_back(c);
        c *= 2;
        c = c% 1000000007;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i< n; i++)
    {
        t += a[i]*(counts[i] - counts[n-i-1]);
        t = t%1000000007;
    }
    cout << t%1000000007;
    return 0;
}
