#include "./maze.h"
// #include "./traverser.h"
#include <iostream>
using namespace std;


int main() {
    Maze maze;
    int * start = maze.get_start(); // Get starting position of the maze
    maze.solve_maze(start); // Begin solving the maze
    maze.writeMazeToFile(); // Write the solved maze to a txt file

    return 0;
}