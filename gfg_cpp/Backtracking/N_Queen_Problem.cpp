/*

    N-Queen Problem :-  
In this we discusses the working and the concept behind the famous N-Queen Problem.
    Using Backtracing.. Cut down the recursion tree as soon as, we find infeasibility..
    
    Ref :-  https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/
    Ref2:-  https://www.geeksforgeeks.org/printing-solutions-n-queen-problem/

*/ 

#include<bits/stdc++.h>
#define N 4
using namespace std;

int board[N][N];

void printSolution(int board[N][N])
{   
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int row, int col)   //  In this we check queen position with previous queens..
{
    for (int i=0; i<col; i++)   //  Check the entire row on column wise..
    {
        if (board[row][i])
            return false;
    }

    for (int i=row, j=col; (i>=0 && j>=0); i--, j--)    //  Check the Upper Diagonal..
    {
        if (board[i][j])
            return false;
    }

    for (int i=row, j=col; (i<N && j>=0); i++, j--)     //  Check the Lower Diagonal..
    {
        if (board[i][j])
            return false;
    }
    return true;
}

bool solveRec(int col)
{
    if (col == N)
        return true;
    
    for (int i=0; i<N; i++){  
        if (isSafe(i, col)){
            board[i][col] = 1;

            if (solveRec(col+1))
                return true;
        
            board[i][col] = 0;
        }
    }
    return false;
}

bool solve()
{
    if (solveRec(0) == false)
    {
        cout << "Solution doesn't exist.." << endl;
        return false;
    }
    printSolution(board);
    return true;
}

int32_t main()
{
    solve();
    return 0;
}