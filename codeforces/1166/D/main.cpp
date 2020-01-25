#include <bits/stdc++.h>

using namespace std;


vector <long long> v;
long long f[100];

void solve(long long a, long long b, long long m)
{
    v.resize(0);
    v.push_back(a);
    long long sum = a;
    while (sum+1 <= b)
    {
        v.push_back(sum+1);
        sum += v[v.size()-1];
    }
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        if (i == 13)
            i = 13;
        long long k = min(m-1, (b-v[n-1])/f[n-1-i]);
        for (int j = 0 ; i+j < n; j++)
            v[i+j] += f[j]*k;
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    f[1] = 1;
    f[0] = 1;
    for (int i = 2; f[i-1]*2LL < 1e18; i++)
        f[i] = f[i-1]*2;
    cin >> test;
    while (test--)
    {
        long long a, b, m;
        cin >> a >> b >> m;
        solve(a, b, m);
        if (v[v.size()-1] == b)
        {
            cout << v.size() << " ";
            for (int i = 0; i < v.size(); i++)
                cout << v[i] << " ";
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}
