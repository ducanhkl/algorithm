#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> v;
int cnt[100];

void primefactor(int x)
{
    for (int i = 2; i <= sqrt(n); i++)
        if (x%i == 0)
    {
        v.push_back(i);
        while (x%i == 0)
            x /= i;
    }
    if (x > 1)
        v.push_back(x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n == 1)
    {
        cout << 1 << " " << 0;
        return 0;
    }
    primefactor(n);
    for (int i = 0; i < v.size(); i++)
    {
        cnt[i] = 0;
        while (n%v[i] == 0)
            n /= v[i], cnt[i] ++;
    }
    double t = *max_element(cnt, cnt+v.size());
    int ans = 1;
    for (int i = 0; i < v.size(); i++)
        ans = ans*v[i];
    int ck = 0;
    int xx = pow(2, ceil(log2(t)));
    for (int i = 0; i < v.size(); i++)
        if (cnt[i] < xx)
    {
        ck = 1;
    }
    cout << ans << " " <<  ceil(log2(t))+ck;
    return 0;
}
