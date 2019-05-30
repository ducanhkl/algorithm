#include <bits/stdc++.h>

using namespace std;


int main ()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] == '(')
                cnt1++;
            if (a[i] == ')')
                cnt2++;
        }
    for (int i = 1; i <= n; i++)
        if (a[i] == '?' && cnt2 != 0)
            a[i] = '(', cnt2 --;
    for (int i = n; i >= 1; i--)
        if (a[i] == '?' && cnt1 != 0)
            a[i] = ')', cnt1 --;
    if (cnt1 || cnt2)
    for (int i = 1; i <= n; i++)
        if (a[i] == '?')
            v.push_back(i);
    if (v.size()%2)
    {
        cout << ":(";
        return 0;
    }
    for (int i = 0; i < v.size(); i++)
        a[v[i]] = '(', a[v.size()-i-1] = ')';
    int cnt = 0;
    for (int i = 1; i <= n; i)
}
