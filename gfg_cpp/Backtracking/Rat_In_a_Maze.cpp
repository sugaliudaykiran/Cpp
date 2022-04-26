/*

Rat In a Maze   :-
    In this we discusses the famous Rat In a Maze Problem using Backtracking.

    Ref :-  https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/
    Ref2 :- https://www.geeksforgeeks.org/rat-in-a-maze-problem-when-movement-in-all-possible-directions-is-allowed/
*/ 

#include<bits/stdc++.h>
using namespace std;

#define N 4

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N]);

void printSol(int sol[N][N])
{
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++)
        {
            cout << sol[i][j] << " ";
        }cout << endl;
    }
}

bool isSafe(int maze[N][N], int x, int y)
{
    if (x >= 0 && x < N && y < N && maze[x][y] == 1)
        return true;
    return false;
}
/* 
This function solves the Maze problem using Backtracking.It mainly uses solveMazeUtil() to solve the problem. It
    returns false if no path is possible, otherwise return true and prints the path in the form of 1s. Please note
     that there may be more than one solutions, this function prints one of the feasible solutions
*/
bool solveMaze(int maze[N][N])
{
    int sol[N][N] = { {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0},
                      {0, 0, 0, 0} };
    if (solveMazeUtil(maze, 0, 0, sol) == false){
        cout << "Solution doesn't exist";
        return false;
    }
    printSol(sol);
    return true;
}

bool solveMazeUtil(int maze[N][N], int x, int y, int sol[N][N])
{
    if (x == N-1 and y == N-1 and maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }
// Check if maze[x][y] is valid
    if (isSafe(maze, x, y) == true) {
        // Check if the current block is already part of
        // solution path.
        if (sol[x][y] == 1)
            return false;
        // mark x, y as part of solution path
        sol[x][y] = 1;
        /* Move forward in x direction */
        if (solveMazeUtil(maze, x + 1, y, sol) == true)
            return true;
        // If moving in x direction doesn't give solution
        // then Move down in y direction
        if (solveMazeUtil(maze, x, y + 1, sol) == true)
            return true;
        // If none of the above movements work then
        // BACKTRACK: unmark x, y as part of solution path
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int32_t main()
{   
    int maze[N][N] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };
    
    solveMaze(maze);

    return 0;
}