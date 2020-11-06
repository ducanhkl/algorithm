#include <iostream>

using namespace std;

int n, a[200];

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i = n; i >= 1; i--)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
