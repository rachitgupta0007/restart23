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

void solve()
{
    int n;
    cin >> n;
    int a[n], dp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dp[0] = a[0];
    dp[1] = a[1];
    dp[2] = a[2];
    for (int i = 3; i < n; i++)
    {
        dp[i] = min(dp[i-3], min(dp[i-1], dp[i-2]))+a[i];
        
    }
    cout << min(dp[n - 3], min(dp[n - 1], dp[n - 2]));
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