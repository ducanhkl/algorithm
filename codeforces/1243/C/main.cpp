#include <bits/stdc++.h>

using namespace std;

long long n;
vector <int> ans;
long long res = 0;

int main()
{
    cin >> n;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n%i == 0)
        {
            ans.push_back(i);
            if (n/i !=i && i != 1)
                ans.push_back(n/i);
        }
    }
    if (ans.size() == 0)
    {
        cout << n;
        return 0;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = i+1; j < ans.size(); j++)
        {
            if (__gcd(ans[i], ans[j]) == 1)
            {
                cout << 1;
                return 0;
            }
        }
    }
    cout << ans[0];
    return 0;
}
