#include <bits/stdc++.h>

using namespace std;

map <string, string> t;
int n, m;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        t[s2] = s1;
    }
    for (int i = 1; i <= m; i++)
        {
            string s1, s2;
            cin >> s1 >> s2;
            string s3 = "";
            for (int i = 0; i < s2.length()-1; i ++)
                s3 = s3 + s2[i];
            cout << s1 << " " << s2 << " #" << t[s3] << endl;
        }
    return 0;
}
