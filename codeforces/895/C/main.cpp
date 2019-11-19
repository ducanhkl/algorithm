include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
const long long mod = 1e9+7;
int prime[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
int a[maxn], n;
long long ans = 1;
vector <int> v;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j <= 19; j++)
            while (a[i]  % (prime[j]*prime[j]) == 0)
                a[i] /= (prime[j]*prime[j]);
    }
    for (int i = 1; i <= n; i++)
    {
        int num = 0;
        for (int j = 1; j <= 19; j++)
            if ((a[i] % prime[j]) == 0)
                num ^= (1<<j);
        for (int j = 0; j < v.size(); j++)
            num = min(num, v[j]^num);
        if (num)
            v.push_back(num);
    }
    for (int i = v.size(); i < n; i++)
        ans = (ans*2LL)%mod;
    cout << (ans+mod-1)%mod;
    return 0;
}
