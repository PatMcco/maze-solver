#ifndef ASSIGNMENT_2_STACK_H
#define ASSIGNMENT_2_STACK_H

class Stack {
private:
struct Node {
        int m_x;
        int m_y;
        Node* m_next {nullptr};
        Node* m_prev {nullptr};
};
public:
    Node* m_top {nullptr};
    Node* m_bottom {nullptr};
    void push(int, int);
    void pop();
    int get_x_coordinate() const;
    int get_y_coordinate() const;
};


#endif //ASSIGNMENT_2_STACK_H
