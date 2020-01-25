#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair

using namespace std;


string a[40];
int n, dd[50][3000];
vector <string> b[40];

bool cmp (string s1, string s2)
{
    return s1.size() > s2.size();
}
bool check(string s1, string s2)
{
    for (int i = s2.length()-1, j = s1.length()-1; i >= 0; i--, j--)
        if (s2[i] != s1[j])
            return false;
    return true;
}
int main()
{
    freopen("inp.txt", "r", stdin);
    memset(dd, 0, sizeof(dd));
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    int k = 0;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int dem = 0;
        for (int j = 1; j < i; j++)
            if (a[j] == s)
                dem = j;
        int t;
        if (dem == 0)
            dem = ++k;
        a[dem] = s;
        cin >> t;
        for (int j = 1; j <= t; j++)
            cin >> s, b[dem].push_back(s);
    }
    for (int i = 1; i <= k; i++)
    {
        sort(b[i].begin(), b[i].end(), cmp);
        for (int j = 0; j < b[i].size(); j++)
                for (int jj = j+1; jj < b[i].size(); jj++)
                    if (check(b[i][j], b[i][jj]))
                        {
                            b[i].erase(b[i].begin()+jj);
                            jj --;
                        }

    }
    cout << k << endl;
    for (int i = 1; i <= k; i++)
    {
        cout << a[i] << " ";
        cout << b[i].size() << " ";
        for (int j = 0 ; j < b[i].size(); j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    return 0;
}
