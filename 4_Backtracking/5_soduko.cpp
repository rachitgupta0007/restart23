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

bool checkPut(int soduko[][9], int x, int y, int val)
{
    // check vertically
    for (int i = 0; i < 9; i++)
    {
        if (soduko[i][y] == val)
            return false;
    }
    // check horizontally
    for (int j = 0; j < 9; j++)
    {
        if (soduko[x][j] == val)
        {
            return false;
        }
    }
    // check in subgrid
    int sx = (x / 3) * 3;
    int sy = (y / 3) * 3;
    for (int i = sx; i < sx + 3; i++)
    {
        for (int j = sy; j < sy + 3; j++)
        {
            if (soduko[i][j] == val)
            {
                return false;
            }
        }
    }
    return true;
}
void print(int soduko[][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << soduko[i][j] << " ";
        }
        cout << endl;
    }
}
bool solveSoduko(int soduko[][9], int x, int y)
{
    if (x == 9)
    { // if j==9 we do i=i+1,j=0
        print(soduko);
        return true;
    }
    if (y == 9)
    {
        return solveSoduko(soduko, x + 1, 0);
    }
    if (soduko[x][y] != 0)
    {
        return solveSoduko(soduko, x, y + 1);
    }

    for (int k = 1; k <= 9; k++)
    {

        if (checkPut(soduko, x, y, k))
        {
            soduko[x][y] = k;
            bool result = solveSoduko(soduko, x, y + 1);
            if (result)
            {
                return true;
            }
        }
    }
    soduko[x][y] = 0;
    return false;
}

void solve()
{
    int soduko[9][9] = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    bool check = solveSoduko(soduko, 0, 0);
    cout << check;
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