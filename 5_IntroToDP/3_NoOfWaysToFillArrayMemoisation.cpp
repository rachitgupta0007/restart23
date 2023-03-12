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
vector<int> memo;
// no of ways to fill an array with 0 and 1 such that there is no consecutive 1
int ways(int n)
{
    if (n == 1 || n == 2)
    {
        return n + 1;
    }
    if (memo[n] != -1)
    {
        return memo[n];
    }
    int ans = ways(n - 1) + ways(n - 2);
    memo[n] = ans;
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    memo.resize(n + 1, -1);
    cout << ways(n);
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