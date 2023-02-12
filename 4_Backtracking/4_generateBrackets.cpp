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

int generateBrackets(string output, int n, int openCount, int closeCount, int i)
{
    if(i==2*n){
        cout << output << endl;
        return 1;
    }
    int ways = 0;
    //condition to place the closing bracket
    if(openCount>closeCount){
       ways+= generateBrackets(output + ')', n, openCount, closeCount + 1, i + 1);
    }
    //condition to place the opening bracket
    if(openCount< n){
       ways+= generateBrackets(output + '(', n, openCount + 1, closeCount, i + 1);
    }
    return ways;
}

void solve()
{
    string output;
    int n;
    cin >> n;
    int ways = generateBrackets(output, n, 0, 0, 0);
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