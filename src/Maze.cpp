#include "Maze.h"
#include <iostream>
#include <fstream>
#include <vector>

//variables
std::vector<std::string> maze_lines;
const int END[] = {49, 49};
const int START[] = {1, 1};
bool solved = false;
std::string line;
int current_x;
int current_y;
Stack stack;


 void Maze::read_maze(std::string& filepath) {
    std::ifstream maze_file(filepath);
    if (!maze_file.is_open()) {
        std::cout << "Error opening file: file not found." << std::endl;
        return;
    }
    while (getline(maze_file, line)) {
        maze_lines.push_back(line);
    }
}

//change this function after solving maze
void Maze::print_maze() {
    for (std::string& maze_line : maze_lines) {
        std::cout << maze_line << std::endl;
    }
}

void Maze::solve_maze(std::string& filepath) {
    read_maze(filepath);
    move(START[0], START[1]);
    while (!solved) {
        check_path(START[0], START[1]);

        //check for end condition by comparing current stack coordinates to END
        if(stack.get_x_coordinate() == END[0] &&
            stack.get_y_coordinate() == END[1]) {
            solved = true;
        }
    }
 }
//add node to stack and mark as visited with '#'
void Maze::move(int x, int y) const {
     if(maze_lines[x][y] == ' ') {
        stack.push(x, y);
        maze_lines[x][y] = VISITED;
     }
     else if(maze_lines[x][y] == VISITED) {
         check_path(x, y);
     }

}

void Maze::check_path(int x, int y) const {
    if (maze_lines[x - 1][y] == ' ') {
        move(x - 1 , y);
    }
    else if(maze_lines[x + 1][y] == ' ') {
        move(x + 1, y);
    }
    else if(maze_lines[x][y + 1] == ' ') {
        move(x, y + 1);
    }
    else if(maze_lines[x][y - 1] == ' ') {
        move(x, y - 1);
    } else {
        go_back();
    }
}

void Maze::go_back() const {
    stack.pop();
    current_x = stack.get_x_coordinate();
    current_y = stack.get_y_coordinate();
    move(current_x, current_y);
}

