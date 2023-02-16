#ifndef ASSIGNMENT_2_MAZE_H
#define ASSIGNMENT_2_MAZE_H
#include <iostream>
#include "Stack.h"


class Maze {
private:
    const char FENCE = '|';
    const char WALL = '-';
    const char PATH = ' ';
    const char VISITED = '#';

public:
    void move(int, int) const;
    static void print_maze();
    static void read_maze(std::string&);
    void solve_maze(std::string&);
    void check_path(int, int) const;
    void go_back() const;
};


#endif //ASSIGNMENT_2_MAZE_H
