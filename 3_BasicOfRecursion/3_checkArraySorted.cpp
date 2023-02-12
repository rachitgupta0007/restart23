#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define F first
#define S second
#define pb push_back
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

//complexity time O(n) and space O(n)
bool isArraySorted(int *arr, int n)
{
    if (n == 1)
    {
        return true;
    }
    if (arr[0] < arr[1])
    {
        return isArraySorted(arr + 1, n - 1);
    }
    return false;
}
void solve()
{
    int n;
    cin >> n;
    int *arr = new int();
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool sorted = isArraySorted(arr, n);
    if (sorted)
    {
        cout << "Array is sorted";
    }
    else
    {
        cout << "Array not sorted";
    }
}
int32_t main()
{

    clock_t z = clock();

    int t = 1;
    // cin>>t;
    while (t--)
        solve();

    cerr << "\nRun Time :" << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}