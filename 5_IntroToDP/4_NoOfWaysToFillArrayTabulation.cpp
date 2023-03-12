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
vector<int> arr;
// no of ways to fill an array with 0 and 1 such that there is no consecutive 1
void ways(int n)
{
    
        arr[1] = 2;
        arr[2] = 3;
    for (int i = 3; i <= n;i++){
        arr[i] = arr[i - 2] + arr[i - 1];
    }
    cout << arr[n];
}
void solve()
{
    int n;
    cin >> n;
    arr.resize(n + 1, -1);
    ways(n);
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