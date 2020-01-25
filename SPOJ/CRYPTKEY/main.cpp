#include <bits/stdc++.h>
#define maxn 50004

using namespace std;

int n, t;
long long a[maxn], dd[maxn], k;

vector <long long> prime (long long h)
{
    vector <long long> ans;
    long long d = 2;
    while (d*d <= h)
        {
            if (h%d == 0)
            {
                long long tmp = 1;
                while(h%d == 0)
                    tmp *= d, h/=d;
                ans.push_back(tmp);
                d ++;
            }
            d++;
        }
    if (ans.empty() || h > 0)
        ans.push_back(h);
    return ans;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        memset(dd, 0 ,sizeof(dd));
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cin >> k;
        vector  <long long> v = prime(k);
        for (int i = 0; i < v.size(); i++)
            for (int j = 1; j <= n; j++)
                if (a[j] % v[i] == 0)
                    dd[i] = __gcd(dd[i], a[j]);
        int check = true;
        for (int i = 0; i < v.size(); i++)
            if (dd[i] == 0 || k%dd[i])
                check = false;
        if (check)
            cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}
