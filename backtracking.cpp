//
//  main.cpp
//  Backtracking Algorithm

#include <iostream>
#include <chrono>
#include <stdio.h>
using namespace std;
using namespace std::chrono;

//maze size
#define N 10
 
bool solveMazeUtil(
    int maze[N][N], int x,
    int y, int sol[N][N]);
 
// print solution matrix
void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}
 
//checks if (x,y) coordinates exist in maze
bool isSafe(int maze[N][N], int x, int y)
{
    if (
        x >= 0 && x < N && y >= 0
        && y < N && maze[x][y] == 1)
        return true;
 
    return false;
}
 
//This function solves the maze by backtracking
bool solveMaze(int maze[N][N])
{
    int sol[N][N] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, };
 
    if (solveMazeUtil(
            maze, 0, 0, sol)
        == false) {
        cout << "Solution doesn't exist" << endl;
        return false;
    }
 
    printSolution(sol);
    return true;
}
 
// A recursive function to solve maze
bool solveMazeUtil(
    int maze[N][N], int x,
    int y, int sol[N][N])
{
    if (
        x == N - 1 && y == N - 1
        && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }
 
    if (isSafe(maze, x, y) == true) {
          if (sol[x][y] == 1)
              return false;
       
        sol[x][y] = 1;
 
        if (solveMazeUtil(
                maze, x + 1, y, sol)
            == true)
            return true;
 
        if (solveMazeUtil(
                maze, x, y + 1, sol)
            == true)
            return true;
        
        sol[x][y] = 0;
        return false;
    }
 
    return false;
}

int main()
{
    int maze[N][N] ={
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 1, 1, 1, 0, 1, 0, 0 },
    { 0, 0, 1, 0, 0, 1, 1, 0, 0, 0 },
    { 0, 0, 1, 1, 1, 1, 1, 1, 0, 0 },
    { 0, 0, 1, 1, 0, 1, 1, 0, 1, 1 },
    { 0, 0, 1, 0, 1, 0, 1, 1, 1, 0 },
    { 0, 0, 1, 0, 1, 0, 0, 1, 1, 1 },
    { 0, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
    { 0, 1, 0, 1, 1, 1, 0, 1, 0, 0 },
    { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 },
    };
    
    auto start = high_resolution_clock::now();
    solveMaze(maze);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken: " << duration.count() << " microseconds." << endl;
    return 0;
};
