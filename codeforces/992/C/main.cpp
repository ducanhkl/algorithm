#include <iostream>

using namespace std;
long long n, k;
int main()
{
    cin >> n >> k;
    for (long long i = k; i >= 1; i--)
        if ((n+1)%i)
    {
        cout << "No";
        return 0;
    }
    cout << "Yes";
    return 0;
}
