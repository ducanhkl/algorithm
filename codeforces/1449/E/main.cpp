#include <bits/stdc++.h>

using namespace std;

set <long long> fact(long long n)
{
    set <long long> res;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            res.insert(i);
            res.insert(n/i);
        }
    }
    res.erase(1);
    return res;
}

void solve(long long n)
{
    set<long long> s = fact(n);
    vector<long long> ans;

    while(s.size())
    {
        if (ans.size() == 0)
        {
            long long x = *s.begin();
            ans.push_back(x);
            s.erase(x);
        } else
        {
            for (long long x : s)
            {
                if (__gcd(x, ans.back()) != 1)
                {
                    ans.push_back(x);
                    s.erase(x);
                    break;
                }
            }
        }
    }
    for (auto x: ans)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << !(__gcd(ans[0], ans.back()) != 1);
    cout << endl;
}

int main()
{
    // freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        long long n;
        cin >> n;
        solve(n);
    }
    return 0;
}
