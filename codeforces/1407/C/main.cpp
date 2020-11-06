#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5+100;

int n;
int a[maxn];
bool test = false;
vector<int> v = {1, 2, 3, 4 ,5 };

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    if (test) {
        return v[i-1] % v[j-1];
    } else {
        int res;
        cin >> res;
        return res;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    if (test) {
        n = v.size();
    } else
    cin >> n;
    int firstPos = 1;
    for (int i = 2; i <= n; i++)
    {
        int x1 = ask(firstPos, i);
        int x2 = ask(i, firstPos);
        if (x2 < x1)
        {
            a[firstPos] = x1;
            firstPos = i;
        } else
        {
            a[i] = x2;
        }
    }
    a[firstPos] = n;
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
