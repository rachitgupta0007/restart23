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
void printAllSubset(char *input,char *output,int i,int j)
{
    if (input[i]=='\0'){
        output[j] = '\0';
        cout << output<<endl;
        return;
    }
   
    //exclude 1st letter and go and print
    printAllSubset(input, output, i + 1, j );
    //include 1st  letter and go and print
     output[j] = input[i];
    printAllSubset(input, output, i + 1, j + 1);


}

void solve()
{
    char input[100];
    cin >> input;
    char output[100];
    printAllSubset(input, output,0,0);
    
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