//
//  main.cpp
//  Wall Follower Algorithm
//

#include <iostream>
#include <queue>
#include <chrono>
using namespace std;
using namespace std::chrono;
#define ROW 10
#define COL 10
 
//store matrix cell coordinates
struct Point
{
    int x;
    int y;
};
 
// A Data Structure for queue used in BFS
struct queueNode
{
    Point pt;  
    int dist;  
};
 
// checks if cell is in matrix
bool isValid(int row, int col)
{
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL);
}
 
//directions to navigate rows and columns
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};
 
//find the shortest path between source and destination
int BFS(int mat[][COL], Point src, Point dest)
{
    if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
        return -1;
 
    bool visited[ROW][COL];
    memset(visited, false, sizeof visited);
     
    visited[src.x][src.y] = true;
 
    queue<queueNode> q;
     
    queueNode s = {src, 0};
    q.push(s);  
 
    while (!q.empty())
    {
        queueNode curr = q.front();
        Point pt = curr.pt;
 
        if (pt.x == dest.x && pt.y == dest.y)
            return curr.dist;
 
        q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];
             
            if (isValid(row, col) && mat[row][col] &&
               !visited[row][col])
            {
                visited[row][col] = true;
                queueNode Adjcell = { {row, col},
                                      curr.dist + 1 };
                q.push(Adjcell);
            }
        }
    }
    return -1;
}
int main()
{
    int mat[ROW][COL] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 },
        { 0, 1, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 0, 1, 1, 0, 0, 0 },
        { 0, 0, 1, 1, 1, 1, 1, 1, 0, 0 },
        { 0, 0, 1, 1, 0, 1, 1, 0, 1, 1 },
        { 0, 0, 1, 0, 1, 0, 1, 1, 1, 0 },
        { 0, 0, 1, 0, 1, 0, 0, 1, 1, 1 },
        { 0, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
        { 0, 1, 0, 1, 1, 1, 0, 1, 0, 0 },
        { 0, 1, 1, 1, 1, 0, 1, 1, 0, 1 },
    };
 
    Point source = {0, 0};
    Point dest = {9, 9};
    
    auto start = high_resolution_clock::now();
    int dist = BFS(mat, source, dest);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
 
    if (dist != -1){
        cout << "Shortest Path is " << dist << endl;
        cout << "Time taken: " << duration.count() << " microseconds." << endl;
    }
    else{
        cout << "Shortest Path doesn't exist" << endl;
        cout << "Time taken: " << duration.count() << " microseconds." << endl;
    }
    return 0;
};
