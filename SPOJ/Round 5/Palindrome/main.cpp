#include <bits/stdc++.h>
#define maxn 100001


using namespace std;
char s[maxn];
int n, k;

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    int dem = 0;
    n --;
    int x = n / 2;
    while(x >= 0)
        {
            if (s[x] != s[n - x]) dem ++;
            x --;
        }
    n ++;
    if (k < dem)
        return cout << "No" << endl, 0;
    if (k > n)
        return cout << "No" << endl, 0;
    if (dem == k)
        return cout << "Yes" << endl, 0;
    if (k > dem&& k<=2*dem)
        return cout << "Yes" << endl, 0;
    if (n * 2 == 1)
        if (k <= n)
            return cout << "Yes" << endl, 0;
    if (n%2 == 0)
        if ((k-2*dem) %2 == 1)
            return cout << "No" << endl, 0;
        else return cout << "Yes" << endl, 0;
    return 0;
}
