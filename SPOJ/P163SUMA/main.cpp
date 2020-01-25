#include <bits/stdc++.h>
using namespace std;

long long ans = 0, k;
int n, a[10000];
string s;

int main()
{
    freopen("tên file", "lệnh, thường là r, w, r+, w+, tương ứng là read và write" , cái này là luồng);
    //ios_base::sync_with_stdio(false);
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        a[(int)s[i]]++;
    for (int i = 0; i <= 300; i++)
        for (int j = i+1; j <= 300; j++)
            if (a[i] < a[j])
                swap(a[i], a[j]);
    for (int i = 0; i <= 300 && k > 0; i++)
        if (k <= a[i])
            ans += k*k, k = 0;
        else
            ans += a[i]*a[i], k -= a[i];
    cout << ans;
}
