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

//matrix expo for liner occurance - O(kpow 3 log n)
// memoziation and dp O(n)
// time comp O(2 pow n) and space O(n)
int binaryString(int n) // n=3 ans = 5
{
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 2;
    }
 
    return binaryString(n - 2) + binaryString(n - 1);
    // n-2 as at 0 index 1 is there we fixed 0 at 1st index
    //n-1 as at 0 index 2 is there we can get n-1 
}
void solve()
{
    int n;
    cin >> n;
    int count = binaryString(n);
    cout << count;
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