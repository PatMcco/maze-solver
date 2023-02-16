#ifndef ASSIGNMENT_2_MAZE_H
#define ASSIGNMENT_2_MAZE_H

#include <iostream>
#include <vector>
#include "Stack.h"


class Maze {
private:
    const char VISITED = '#';
    const int START = 1;
    const int END = 49;

public:
    void move(int, int) const;

    static void read_maze(std::string &);

    void solve_maze(std::string &) const;

    void check_path(int, int) const;

    static void go_back();

    static void print_finished_maze(std::vector<std::string> &);
};


#endif //ASSIGNMENT_2_MAZE_H
