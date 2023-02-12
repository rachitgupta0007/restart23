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

// matrix expo for liner occurance - O(kpow 3 log n)
//  memoziation and dp O(n)
//  time comp O(2 pow n) and space O(n)
// ways - (2 pow n) - 1 // 3->7, 4-> 15, 5->31, 6->63 >
int towerOfHanoi(int n, string source, string helper, string destination) // n=3 ans = 5
{
    if (n == 0)
    {
        return 0;
    }

    int step1 = towerOfHanoi(n - 1, source, destination, helper);

    // int step2 = towerOfHanoi(1, source, helper, destination);
    int step2 = 1;
    // cout << source << " -> " << destination << "\n";

    int step3 = towerOfHanoi(n - 1, helper, source, destination);
    return step1 + step2 + step3;
}
void solve()
{
    int n;
    cin >> n;
    int ways = towerOfHanoi(n, "source", "helper", "destination");
    cout << ways;
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