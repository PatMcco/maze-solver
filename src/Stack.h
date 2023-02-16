#ifndef ASSIGNMENT_2_STACK_H
#define ASSIGNMENT_2_STACK_H

class Stack {
private:
    struct Node {
        int m_x;
        int m_y;
        Node *m_next{nullptr};
    };
public:
    Node *m_top{nullptr};

    void push(int, int);

    void pop();

    int get_x() const;

    int get_y() const;
};


#endif //ASSIGNMENT_2_STACK_H
