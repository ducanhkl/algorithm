#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

vector <string> v;
int n;
string a[maxn][20];

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s= "";
        for (int j = 1; j <= 6; j++)
            cin >> a[i][j], a[i][j+6] = a[i][j];
        for (int j = 1; j <= 6; j++)
            s = s + a[i][j];
        v.push_back(s);
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++)
        if (v[i] == v[i-1])
            return cout << "Twin snowflakes found.", 0;
    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= 6; j++)
        {
            string s = "";
            for (int k = j; k <= j+5; k++)
                s = s + a[i][k];
            //cout << s << endl;
            int pos = lower_bound(v.begin(), v.end(), s) - v.begin();
            if (v[pos] == s)
                return cout << "Twin snowflakes found.", 0;
        }
    cout << "No two snowflakes are alike.";
    return 0;
}
