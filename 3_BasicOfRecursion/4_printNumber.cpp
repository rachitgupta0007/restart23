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
void printInc(int n)
{
    if (n == 0)
    {

        return;
    }
    printInc(n - 1);
    cout << n;
}
void printDec(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n;
    printDec(n - 1);
}
void solve()
{
    int n;
    cin >> n;
    printInc(n);
    cout << "\n";
    printDec(n);
}
int32_t main()
{

    clock_t z = clock();

    int t = 1;
    // cin>>t;
    while (t--)
        solve();

    cerr << "Run Time :" << ((double)(clock() - z) / CLOCKS_PER_SEC);
    return 0;
}