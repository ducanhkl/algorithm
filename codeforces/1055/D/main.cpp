#include <bits/stdc++.h>

using namespace std;

const int maxn = 4000;
int n;
string s[maxn], t[maxn], s1, s2, s3, s4;
int f[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == t[i])
            continue;
        int b = 5000, e = 0;
        for (int j = 0; j < s[i].size(); j++)
            if (s[i][j] != t[i][j])
                b = min(b, j), e = max(e, j);
        if (s1.size() == 0)
        {
            s1 = s[i].substr(b, e-b+1);
            s2 = t[i].substr(b, e-b+1);
            s3 = s[i].substr(0, b);
            s4 = t[i].substr(e+1);
            reverse(s3.begin(), s3.end());
        }
        else
        {
            string mid1 = s[i].substr(b, e-b+1);
            string mid2 = t[i].substr(b, e-b+1);
            //cout << mid1 << " " << mid2;
            if (mid1 != s1 || mid2 != s2)
                {
                    //cout << mid1 << " " << mid2 << endl;
                    return cout << "NO", 0;
                }
            string pre = s[i].substr(0, b);
            string sub = t[i].substr(e+1);
            reverse(pre.begin(), pre.end());
            //cout << pre << " " << sub << endl;
            //<< s3 << " " << s4 << endl;
            int j = 0;
            for (j = 0; j < min(s3.size(), pre.size()); j++)
                if (pre[j] != s3[j])
                    break;
            s3 = s3.substr(0, j);
            for (j = 0; j < min(sub.size(), s4.size());  j++)
                if (sub[j] != s4[j])
                    break;
            s4 = s4.substr(0, j);
        }
    }
    //cout << s3 << " " << s4 << endl;
    reverse(s3.begin(), s3.end());
    s1 = s3 + s1 + s4;
    s2 = s3 + s2 + s4;
    memset(f, 0, sizeof(f));
    int j = 0;
    for (int i = 1; i < s1.size(); i++)
        {
            while (j != 0 && s1[i] != s1[j])
                j = f[j];
            if (s1[i] == s1[j])
                j++;
            f[i+1] = j;
        }
    for (int i = 1; i <= n; i++)
    {
        int k;
        for (j = 0, k = 0; k < s[i].size(); k++)
        {
            while (j != 0 && s[i][k] != s1[j])
                j = f[j];
            if (s[i][k] == s1[j])
                j++;
            if (j == s1.size())
                break;
        }
        //cout << s1 << endl;
        if (k != s[i].size())
        {
            for (int ii = 0; ii < s1.size(); ii++)
                {
                    s[i][k-s1.size()+1+ii] = s2[ii];
                    //cout << s[i] << endl;
                }
        }
        if (s[i] != t[i])
            return cout << "NO", 0;
    }
    cout << "YES" << endl;
    cout << s1 << endl << s2;
    return 0;
}
