#include <bits/stdc++.h>

using namespace std;

string m2[10];
int dd[10];
map <string, int> m1;
int n, ans = 0 ;

int main()
{
    ios_base::sync_with_stdio(false);
    m1["purple"] = 1;
    m1["green"] = 2;
    m1["blue"] = 3;
    m1["orange"] = 4;
    m1["red"] = 5;
    m1["yellow"] = 6;
    m2[1] = "Power";
    m2[2] = "Time";
    m2[3] = "Space";
    m2[4] = "Soul";
    m2[5] = "Reality";
    m2[6] = "Mind";
    memset(dd, 0, sizeof(dd));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        dd[m1[s]] = 1;
    }
    for (int i = 1; i <= 6; i++)
        if (dd[i] == 0)
            ans ++;
    cout << ans << endl;
    for (int i = 1; i <= 6; i++)
        if (dd[i] == 0)
            cout << m2[i] << endl;
    return 0;
}
