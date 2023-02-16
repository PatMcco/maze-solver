#include <iostream>
#include "Maze.h"
#include <string>
int main(int argc, char* argv[]) {
    // validate filepath from args and read maze
    if (argc != 2) {
        std::cout << "Invalid command line arguments, must enter absolute path" << std::endl;
        return 1;
    }
    std::string filepath = argv[1];
    Maze maze;
    maze.solve_maze(filepath);

    return 0;
}