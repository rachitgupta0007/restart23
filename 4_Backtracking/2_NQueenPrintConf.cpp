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

void printBoard(int board[][20], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool checkAllDirction(int board[][20], int n, int x, int y)
{
    // vertical check
    for (int i = 0; i < x; i++)
    {
        if (board[i][y] == 1)
        {
            return false;
        }
    }

    // horizontal check
    for (int j = 0; j < y; j++)
    {
        if (board[x][j] == 1)
        {
            return false;
        }
    }
    // left diagonal check
    int i = x;
    int j = y;

    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j--;
    }
    // rigtht diagonal
     i = x;
     j = y;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
        i--;
        j++;
    }
    return true;
}
// Complexity is O{n pow n} can be optimise to O(n!)
bool solveNQueen(int board[][20], int n, int i)
{
    // base case we reached when row is ended and placed everything correctlty
    if (n == i)
    {
        printBoard(board, n);
        return true;
    }
    // function
    for (int j = 0; j < n; j++)
    {
        // no other queen is present not at i ,j ie. it's safe to place the queen at i,j
        if (checkAllDirction(board, n, i, j))
        {
            board[i][j] = 1;
            bool checkFurther = solveNQueen(board, n, i + 1);
            if (checkFurther)
            {
                return true;
            } // backtrack
            board[i][j] = 0;
        }
    }
    // we will come out of for loop if there is no position in a column to place position as 1 queen should be present at 1 row
    return false;
}

// printing 1 configuration or checking if configuration possible
void solve()
{
    int board[20][20] = {0};
    int n;
    cin >> n;
    solveNQueen(board, n, 0);
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