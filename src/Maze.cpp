#include "Maze.h"
#include <iostream>
#include <fstream>

// variables
std::vector<std::string> maze_lines;
std::vector<std::string> solved_maze;
bool solved = false;
std::string line;
Stack stack;

// read maze from filepath param into maze_lines vector
 void Maze::read_maze(std::string& filepath) {
    std::ifstream maze_file(filepath);
    if (!maze_file.is_open()) {
        std::cout << "Error opening file: file not found." << std::endl;
        return;
    }
    while (getline(maze_file, line)) {
        maze_lines.push_back(line);
    }
    maze_file.close();
    solved_maze = maze_lines;
}

// solve maze by reading file, moving to next node, and checking for valid moves
void Maze::solve_maze(std::string& filepath) const {
    read_maze(filepath);
    move(START, START);
    while (!solved) {
        check_path(stack.get_x(), stack.get_y());
        //check for end condition by comparing current stack coordinates to END
        if(stack.get_x() == END &&
                stack.get_y() == END) {
            solved = true;
        }
    }
    print_finished_maze(solved_maze);
 }
// add node to stack and mark as visited with '#'
void Maze::move(int x, int y) const {
     stack.push(x, y);
     maze_lines[x][y] = VISITED;
}

// check for valid moves and out of bounds conditions
// hardcoded for 50x50 maze
void Maze::check_path(int x, int y) const {
     if(stack.get_x() - 1 >= 1 &&
        maze_lines[x - 1][y] == ' ') {
         move(x - 1, y);
     } else if(stack.get_x() + 1 < 50 &&
        maze_lines[x + 1][y] == ' ') {
         move(x + 1, y);
     } else if(stack.get_y() + 1 < 50 &&
        maze_lines[x][y + 1] == ' ') {
         move(x, y + 1);
     } else if(stack.get_y() - 1 >= 1 &&
        maze_lines[x][y - 1] == ' ') {
         move(x, y - 1);
     } else {
        go_back();
     }
}

// pop stack until a valid move is found
void Maze::go_back() {
     while(maze_lines[stack.get_x() - 1][stack.get_y()] != ' ' &&
        maze_lines[stack.get_x() + 1][stack.get_y()] != ' ' &&
        maze_lines[stack.get_x()][stack.get_y() - 1] != ' ' &&
        maze_lines[stack.get_x()][stack.get_y() + 1] != ' ') {
            stack.pop();
     }
}

void Maze::print_finished_maze(std::vector<std::string>& solved_maze_lines) {

     std::cout << "Solved maze:" << std::endl;
    while (stack.m_top != nullptr) {
        solved_maze_lines[stack.get_x()][stack.get_y()] = '#';
        stack.pop();
    }
    for (std::string& maze_line : solved_maze_lines) {
        std::cout << maze_line << std::endl;
    }
    // create output file and write solved maze to it
    std::ofstream output(R"(D:\----PROG_C----\CODE\assignment-2-PatMcco\solved\solved_maze.txt)");
    for(int i = 0; i < solved_maze_lines.size(); i++) {
        output << solved_maze_lines[i] << std::endl;
    }
    std::cout << "Solved maze written to file: solved_maze.txt" << std::endl;
}
