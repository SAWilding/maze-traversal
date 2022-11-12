/* Maze class

Member variables:
int mazeGrid - store the maze into a list of integers between 0-3 
string mazeSize - store the selected maze size (small , medium, large)

Methods:
int getPossibleMoves() - return a list of all the possible moves based on location (x, y)
void loadMaze() - reads maze file and stores it into this->mazeGrid
void visitSpace() - turns a space in this->mazeGrid to a 4 to represent that it has been visited
void restoreSpace() - turns a space back to a 0
voide displayMaze() - prints the maze to the console */

#include <fstream>
#include <iostream>
using namespace std;

class Maze {
    private:
        string mazeSize;
        char mazeGrid[5][5];
        int start[2];
        int end[2];

        void loadMaze() {
            // Loads the maze txt file into a 2 dimensional array this->mazeGrid
            string line;
            ifstream myMaze("./maze2.txt"); // load maze file
            int y = 0;
            while (getline(myMaze, line) ) {

                char rowArray[line.length()]; // create array to store each character in line

                for (int x = 0; x < sizeof(rowArray); x++) {
                    rowArray[x] = line[x]; // store each character into rowArray
                    this->mazeGrid[x][y] = rowArray[x]; // Add each row into the mazeGrid
                    if (rowArray[x] == *"2") { // Save the location of the start of the maze into start
                        this->start[0] = x;
                        this->start[1] = y; 
                    }
                    else if (rowArray[x] == *"3"){ // Save the end of the maze into end
                        this->end[0] = x;
                        this->end[1] = y;
                    }
                }
            
        
            y++; 
                
            }

            myMaze.close(); // close maze file
            this->displayMaze(); // print maze for debugging
        }



    public:


        Maze() {
            this->loadMaze();
        }

        void writeMazeToFile() {
            ofstream mazeFile("./finished-maze.txt"); 

            for (int x = 0; x < sizeof(this->mazeGrid[x]); x++) {
                for (int y = 0; y < sizeof(this->mazeGrid[x]); y++) {
                    mazeFile << this->mazeGrid[y][x];
                }
                mazeFile << endl;
            }

            mazeFile.close();
        }

        int * getPossibleMoves(int x, int y) {
             // returns a pointer to an array of all the possible moves the traverser can make at an x y location
            int possibleMoves[4][2] = {{x + 1, y}, {x - 1, y}, {x, y + 1}, {x, y - 1}};
            static int moves[8];
            int movesIndex = 0;
            for (int i = 0; i <= 3; i++) {
                int moveX = possibleMoves[i][0];
                int moveY = possibleMoves[i][1];
                if (this->mazeGrid[moveX][moveY] == *"0" || this->mazeGrid[moveX][moveY] == *"3") {
                    moves[movesIndex] = moveX;
                    // cout << moveX << ": " << movesIndex << endl;
                    movesIndex += 1;
                    moves[movesIndex] = moveY;
                    // cout << moveY << ": " << movesIndex << endl;
                    movesIndex += 1;
                }
            
            }
            int * ptr = &moves[0];

            return ptr;

        }


        void visitSpace(int x, int y) {
            // Converts the give space to an X
            this->mazeGrid[x][y] = *"X";
            cout << endl;
            this->displayMaze();
        }

        void restoreSpace(int x, int y) {
            // Restores a given space to a 0
            this->mazeGrid[x][y] = *"0";
            this->displayMaze();
        }

        void displayMaze() {
            // Displays the maze in the console
            for (int x = 0; x < sizeof(this->mazeGrid[x]); x++) {
                for (int y = 0; y < sizeof(this->mazeGrid[x]); y++) {
                    cout << this->mazeGrid[y][x] << " ";
                }
                cout << endl;
            }
        }

        int * get_start() {
            // Returns the starting position of the maze
            return this->start;
        }

        bool at_end(int x, int y) {
            // Returns true or false if at the end of the maze
            if (this->end[0] == x && this->end[1] == y) {
                return true;
            } 
            else {
                return false;
            }
        }
  
        bool solve_maze(int * move) {
            // Recursively solves the maze 
            bool result;
            this->visitSpace(move[0], move[1]);

            if (this->at_end(move[0], move[1])) {
                return true;
            }

            cout << move[0] << move[1] << endl;

            int * possibleMoves = this->getPossibleMoves(move[0], move[1]);

            cout << possibleMoves[0] << possibleMoves[1] << endl;

            if (possibleMoves[0] == move[0] && possibleMoves[1] == move[1]) {
                this->restoreSpace(move[0], move[1]);
                return false;
            }

            for (int i = 0; 3 > i; i += 2) {

                int moveX = possibleMoves[i];
                int moveY = possibleMoves[i + 1];
                
                if (moveX + moveY == 0) {
                    return false;
                } 
                else {

                int move[2] = {moveX, moveY}; 
                result = this->solve_maze(move);

                if (result) {
                    break;
                }
                }
            }

            if (!result) {
                this->restoreSpace(move[0], move[1]);
                return false;
            }


        }
        
};

