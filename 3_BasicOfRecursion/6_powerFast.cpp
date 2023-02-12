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
// time comp O(lon n) and space O(log n)
int power(int a, int n)
{
    if (n == 1)
    {
        return a;
    }
    int ans = power(a, n / 2);
    if (a % 2 == 0)
    {

        return ans * ans;
    }
    else
        return a * ans * ans;
}
void solve()
{
    int a, n;
    cin >> a >> n;
    int pow = power(a, n);
    cout << pow;
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