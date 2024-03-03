#include <iostream>
#include <vector>

/*
    Question 1:

    Getting the number of paths that solves a maze(MxN)
    
    note: This first maze doesn't have obstacles and just move right
    and down

*/
int countPaths(int r, int c) {

    // If our maze just can move to right and down
    // base case
    if(r == 1 || c == 1)
        return 1;

    // segment tree for left and right
    // recursion call
    int left = countPaths(r-1,c);
    int right = countPaths(r,c-1);

    return left+right;

}

/*
    Question 2:

    Printing the paths to solve the maze(MxN)

    note: The maze doesn't have obstacles, you only can move to
    right and down

*/
void printingPaths(std::string path, int r, int c) {

    // base case
    if(r == 1 && c == 1) {
        std::cout << path << std::endl;
        return;
    }

    // recursion call
    // left recursion call
    if(r > 1)
        printingPaths(path + "V", r-1,c);

    // right recursion call
    if(c > 1)
        printingPaths(path + "H",r,c-1);

}

/*
    Question 3:

    Print the paths including diagonal right(NxM)

    note: the maze doesn't have obstacles 
    you can justo move to right, diagonal right and down;

*/
void printingPathsDiagonal(std::string path, int r, int c) {

    // base case
    if(r == 1 && c == 1) {
        std::cout << path << std::endl;
        return;
    }

    // recursion call
    // left recursion (when goes down)
    if (r > 1)
        printingPathsDiagonal(path + "V", r-1, c);
    
    // mid recursion (when goes diagonally)
    if(r > 1 && c > 1)
        printingPathsDiagonal(path + "D", r-1, c-1);

    // right recursion (when goes right)
    if(c > 1)
        printingPathsDiagonal(path + "H", r, c-1);

}

/*
    Question 4:

    How to solve a maze(MxN) with obstacles

    obs: you can only move to right and down
*/
void pathWithRestrictions(std::string path, std::vector<std::vector<bool>> maze, int r, int c) {

    // Now we've a boolean matrix that dicts where is the 
    // rowns and colums blocked (and we start at 0,0)
    if(r == maze.size()-1 && c == maze[0].size()-1) {
        std::cout << path << std::endl;
        return;
    }

    // Check if is possible to continue the path
    if(maze[r][c])
        return;

    if(r < maze.size()-1) {
        pathWithRestrictions(path + "V", maze, r+1, c);
    }

    if (c < maze[0].size()-1) {
        pathWithRestrictions(path+"H", maze, r, c+1);
    }

}

/*
    Question 5

    including all paths and using the same logic to the maze
    as question 4

*/
void pathsMaze(std::string path, std::vector<std::vector<bool>> maze, int r, int c) {

    // base case
    if(r == maze.size()-1 && c == maze[0].size()-1) {
        std::cout << path << std::endl;
        return;
    }

    // checking if is possible to cross
    if(maze[r][c])
        return;

    // Considering this block in the path
    maze[r][c] = 1;

    
    // recursion call
    // check if is possible to go down
    if(r < maze.size()-1)
        pathsMaze(path + "D", maze, r+1,c);
    
    // check if is possible to go left
    // the row don't change, just the column
    if(c > 0)
        pathsMaze(path + "L", maze, r, c-1);

    //check if is possible to go up
    // the colum don't change, just the row
    if(r > 0)
        pathsMaze(path + "U", maze, r-1,c);

    // check if is possible to go right
    if(c < maze[0].size()-1)
        pathsMaze(path + "R", maze, r, c+1);

    // restoring the original maze (when the function is over)
    // before the function gets removed, also remove the changes
    // that were made by that function
    maze[r][c] = 0; // backtracking

}

/*
    Question 6: The final!!

    print the paths and the matrix of a maze(MxN) that can
    have obstacles.

    obs: you can go to 4 directions (up,left,down,right)
*/
void solveMaze(std::string output, std::vector<std::vector<bool>> maze,std::vector<std::vector<int>> &path, int r, int c, int step) {

    // base call
    if(r == maze.size()-1 && c == maze[0].size()-1) {
        // printing the values of path
        for(int i = 0; i < path.size(); ++i){
            for(int j = 0; j < path[0].size(); ++j)
                std::cout << path[i][j] << " ";
            std::cout << std::endl;
        }
        std::cout << output << std::endl;
        std::cout << std::endl;
        return;
    }

    // checking if we can pass through
    if(maze[r][c])
        return;

    // mark if we pass
    maze[r][c] = 1;
    path[r][c] = step; // step starts at 1

    // recursion call to the directins
    // down
    if(r < maze.size()-1)
        solveMaze(output + "D", maze, path, r+1, c, step+1);


    // left
    if(c > 0)
        solveMaze(output + "L", maze, path, r, c-1, step+1);


    // up
    if(r > 0)
        solveMaze(output + "U", maze, path, r-1, c, step+1);


    //right
    if (c < maze[0].size()-1)
        solveMaze(output + "R", maze, path, r, c+1, step+1);


    // backtracking
    maze[r][c] = 0;
    path[r][c] = 0;

}



int main(){

    std::cout << "Question 1" << std::endl;
    std::cout << countPaths(3,3) << std::endl;
    std::cout << std::endl;
// ---------------------------------------------------
    std::cout << "Question 2" << std::endl;
    std::string output = "";
    printingPaths(output,3,3);
    std::cout << std::endl;
// ---------------------------------------------------
    std::cout << "Question 3" << std::endl;
    output = "";
    printingPathsDiagonal(output,3,3);
    std::cout << std::endl;
// ---------------------------------------------------
    std::cout << "Question 4" << std::endl;
    std::vector<std::vector<bool>> maze;
    output = "";
    maze = {
        {0,0,0,0},
        {0,1,0,0},
        {0,0,0,1},
        {1,0,0,0}
    };
    pathWithRestrictions(output, maze, 0, 0);
    std::cout << std::endl;
// -----------------------------------------------------
    std::cout << "Question 5" << std::endl;
    output = "";
    maze = {
        {0,0,0},
        {0,0,0},
        {0,0,0},
    };
    pathsMaze(output,maze,0,0);
    std::cout << std::endl;
// -----------------------------------------------------
    std::cout << "Question 6" << std::endl;
    output = "";
    maze = {
        {0,0,0},
        {0,0,0},
        {0,0,0},
    };
    std::vector<std::vector<int>> arr;
    arr = {
        {0,0,0},
        {0,0,0},
        {0,0,0},
    };
    solveMaze(output,maze,arr,0,0,1);
    std::cout << std::endl;
}


