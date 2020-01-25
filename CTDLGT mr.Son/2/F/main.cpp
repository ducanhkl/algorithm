#include <bits/stdc++.h>

using namespace std;

int k;
string a, b, ans;
long long numa = 0, numb = 0, numc = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> k >> a >> b;
    while (a.size() < b.size())
        a = '0' + a;
    while (b.size() < a.size())
        b = '0' + b;
    for (int i = 0; i < a.size(); i++)
    {
        numa = numa*k + a[i]-'0';
        numb = numb*k + b[i]-'0';
    }
    numc = numa+numb;
    while (numc != 0)
    {
        ans = ((char)(numc%k+'0')) + ans;
        numc /= k;
    }
    cout << ans;
    return 0;
}
