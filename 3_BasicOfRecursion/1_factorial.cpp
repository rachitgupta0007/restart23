#include <bits/stdc++.h>
using namespace std;
#define int long long int

//complexity time O(n) space O(n)
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int32_t main()
{
    int n;
    cin >> n;
    n = 5;
    int fact = factorial(n);
    cout << fact;
    return 0;
}