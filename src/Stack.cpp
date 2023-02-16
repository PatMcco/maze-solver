#include "Stack.h"

void Stack::push(int x, int y) {
    Node *new_node = new Node;
    new_node->m_x = x;
    new_node->m_y = y;
    new_node->m_next = m_top;
    m_top = new_node;
}

void Stack::pop() {
    Node *node = m_top;
    m_top = m_top ? m_top->m_next : nullptr;
    delete node;
}

int Stack::get_x() const {
    return m_top ? m_top->m_x : 0;
}

int Stack::get_y() const {
    return m_top ? m_top->m_y : 0;
}